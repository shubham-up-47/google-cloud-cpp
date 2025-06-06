// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OAUTH2_AUTHORIZED_USER_CREDENTIALS_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OAUTH2_AUTHORIZED_USER_CREDENTIALS_H

#include "google/cloud/storage/client_options.h"
#include "google/cloud/storage/internal/curl/request_builder.h"
#include "google/cloud/storage/internal/http_response.h"
#include "google/cloud/storage/oauth2/credential_constants.h"
#include "google/cloud/storage/oauth2/credentials.h"
#include "google/cloud/storage/oauth2/refreshing_credentials_wrapper.h"
#include "google/cloud/storage/version.h"
#include "google/cloud/internal/curl_handle_factory.h"
#include "google/cloud/internal/oauth2_authorized_user_credentials.h"
#include "google/cloud/internal/oauth2_cached_credentials.h"
#include "google/cloud/internal/oauth2_credential_constants.h"
#include "google/cloud/status.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <utility>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace oauth2 {

/**
 * Object to hold information used to instantiate an AuthorizedUserCredentials.
 *
 * @deprecated Prefer using the unified credentials documented in @ref guac
 */
struct AuthorizedUserCredentialsInfo {
  std::string client_id;
  std::string client_secret;
  std::string refresh_token;
  std::string token_uri;
  std::string universe_domain;
};

/**
 * Parses a refresh response JSON string into an authorization header.
 *
 * The header and the current time (for the expiration) form a TemporaryToken.
 *
 * @deprecated Prefer using the unified credentials documented in @ref guac
 */
StatusOr<RefreshingCredentialsWrapper::TemporaryToken>
ParseAuthorizedUserRefreshResponse(
    storage::internal::HttpResponse const& response,
    std::chrono::system_clock::time_point now);

/**
 * Parses a user credentials JSON string into an AuthorizedUserCredentialsInfo.
 *
 * @deprecated Prefer using the unified credentials documented in @ref guac
 */
StatusOr<AuthorizedUserCredentialsInfo> ParseAuthorizedUserCredentials(
    std::string const& content, std::string const& source,
    std::string const& default_token_uri =
        google::cloud::oauth2_internal::GoogleOAuthRefreshEndpoint());

/**
 * Wrapper class for Google OAuth 2.0 user account credentials.
 *
 * Takes a AuthorizedUserCredentialsInfo and obtains access tokens from the
 * Google Authorization Service as needed. Instances of this class should
 * usually be created via the convenience methods declared in
 * google_credentials.h.
 *
 * An HTTP Authorization header, with an access token as its value,
 * can be obtained by calling the AuthorizationHeader() method; if the current
 * access token is invalid or nearing expiration, this will class will first
 * obtain a new access token before returning the Authorization header string.
 *
 * @see https://developers.google.com/identity/protocols/OAuth2 for an overview
 * of using user credentials with Google's OAuth 2.0 system.
 *
 * @tparam HttpRequestBuilderType a dependency injection point. It makes it
 *     possible to mock internal libcurl wrappers. This should generally not be
 *     overridden except for testing.
 * @tparam ClockType a dependency injection point to fetch the current time.
 *     This should generally not be overridden except for testing.
 *
 * @deprecated Prefer using the unified credentials documented in @ref guac
 */
template <typename HttpRequestBuilderType =
              storage::internal::CurlRequestBuilder,
          typename ClockType = std::chrono::system_clock>
class AuthorizedUserCredentials;

/// @copydoc AuthorizedUserCredentials
template <>
class AuthorizedUserCredentials<storage::internal::CurlRequestBuilder,
                                std::chrono::system_clock>
    : public Credentials {
 public:
  explicit AuthorizedUserCredentials(
      AuthorizedUserCredentialsInfo const& info,
      ChannelOptions const& channel_options = {});

  explicit AuthorizedUserCredentials(
      google::cloud::oauth2_internal::AuthorizedUserCredentialsInfo info,
      ChannelOptions const& channel_options = {});

  StatusOr<std::string> AuthorizationHeader() override {
    return oauth2_internal::AuthenticationHeaderJoined(*impl_);
  }

 private:
  friend struct AuthorizedUserCredentialsTester;
  AuthorizedUserCredentials(
      google::cloud::oauth2_internal::AuthorizedUserCredentialsInfo,
      Options options, oauth2_internal::HttpClientFactory client_factory);

  StatusOr<std::string> AuthorizationHeaderForTesting(
      std::chrono::system_clock::time_point tp) {
    return oauth2_internal::AuthenticationHeaderJoined(*impl_, tp);
  }

  std::shared_ptr<google::cloud::oauth2_internal::Credentials> impl_;
};

/// @copydoc AuthorizedUserCredentials
template <typename HttpRequestBuilderType, typename ClockType>
class AuthorizedUserCredentials : public Credentials {
 public:
  explicit AuthorizedUserCredentials(AuthorizedUserCredentialsInfo info,
                                     ChannelOptions const& channel_options = {})
      : info_(std::move(info)),
        options_(Options{}.set<CARootsFilePathOption>(
            channel_options.ssl_root_path())),
        clock_() {}

  StatusOr<std::string> AuthorizationHeader() override {
    std::unique_lock<std::mutex> lock(mu_);
    return refreshing_creds_.AuthorizationHeader(clock_.now(),
                                                 [this] { return Refresh(); });
  }

 private:
  StatusOr<RefreshingCredentialsWrapper::TemporaryToken> Refresh() {
    HttpRequestBuilderType builder(
        info_.token_uri, rest_internal::GetDefaultCurlHandleFactory(options_));
    std::string payload("grant_type=refresh_token");
    payload += "&client_id=";
    payload += builder.MakeEscapedString(info_.client_id).get();
    payload += "&client_secret=";
    payload += builder.MakeEscapedString(info_.client_secret).get();
    payload += "&refresh_token=";
    payload += builder.MakeEscapedString(info_.refresh_token).get();
    auto response = std::move(builder).BuildRequest().MakeRequest(payload);
    if (!response) return std::move(response).status();
    if (response->status_code >= 300) return AsStatus(*response);
    return ParseAuthorizedUserRefreshResponse(*response, clock_.now());
  }

  AuthorizedUserCredentialsInfo info_;
  Options options_;
  ClockType clock_;
  mutable std::mutex mu_;
  RefreshingCredentialsWrapper refreshing_creds_;
};

}  // namespace oauth2
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OAUTH2_AUTHORIZED_USER_CREDENTIALS_H
