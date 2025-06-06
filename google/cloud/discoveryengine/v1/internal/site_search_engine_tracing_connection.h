// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/discoveryengine/v1/site_search_engine_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DISCOVERYENGINE_V1_INTERNAL_SITE_SEARCH_ENGINE_TRACING_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DISCOVERYENGINE_V1_INTERNAL_SITE_SEARCH_ENGINE_TRACING_CONNECTION_H

#include "google/cloud/discoveryengine/v1/site_search_engine_connection.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace discoveryengine_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

class SiteSearchEngineServiceTracingConnection
    : public discoveryengine_v1::SiteSearchEngineServiceConnection {
 public:
  ~SiteSearchEngineServiceTracingConnection() override = default;

  explicit SiteSearchEngineServiceTracingConnection(
      std::shared_ptr<discoveryengine_v1::SiteSearchEngineServiceConnection>
          child);

  Options options() override { return child_->options(); }

  StatusOr<google::cloud::discoveryengine::v1::SiteSearchEngine>
  GetSiteSearchEngine(
      google::cloud::discoveryengine::v1::GetSiteSearchEngineRequest const&
          request) override;

  future<StatusOr<google::cloud::discoveryengine::v1::TargetSite>>
  CreateTargetSite(
      google::cloud::discoveryengine::v1::CreateTargetSiteRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> CreateTargetSite(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::CreateTargetSiteRequest const&
          request) override;

  future<StatusOr<google::cloud::discoveryengine::v1::TargetSite>>
  CreateTargetSite(google::longrunning::Operation const& operation) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::BatchCreateTargetSitesResponse>>
  BatchCreateTargetSites(
      google::cloud::discoveryengine::v1::BatchCreateTargetSitesRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> BatchCreateTargetSites(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::BatchCreateTargetSitesRequest const&
          request) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::BatchCreateTargetSitesResponse>>
  BatchCreateTargetSites(
      google::longrunning::Operation const& operation) override;

  StatusOr<google::cloud::discoveryengine::v1::TargetSite> GetTargetSite(
      google::cloud::discoveryengine::v1::GetTargetSiteRequest const& request)
      override;

  future<StatusOr<google::cloud::discoveryengine::v1::TargetSite>>
  UpdateTargetSite(
      google::cloud::discoveryengine::v1::UpdateTargetSiteRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> UpdateTargetSite(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::UpdateTargetSiteRequest const&
          request) override;

  future<StatusOr<google::cloud::discoveryengine::v1::TargetSite>>
  UpdateTargetSite(google::longrunning::Operation const& operation) override;

  future<StatusOr<google::cloud::discoveryengine::v1::DeleteTargetSiteMetadata>>
  DeleteTargetSite(
      google::cloud::discoveryengine::v1::DeleteTargetSiteRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> DeleteTargetSite(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::DeleteTargetSiteRequest const&
          request) override;

  future<StatusOr<google::cloud::discoveryengine::v1::DeleteTargetSiteMetadata>>
  DeleteTargetSite(google::longrunning::Operation const& operation) override;

  StreamRange<google::cloud::discoveryengine::v1::TargetSite> ListTargetSites(
      google::cloud::discoveryengine::v1::ListTargetSitesRequest request)
      override;

  future<StatusOr<google::cloud::discoveryengine::v1::Sitemap>> CreateSitemap(
      google::cloud::discoveryengine::v1::CreateSitemapRequest const& request)
      override;

  StatusOr<google::longrunning::Operation> CreateSitemap(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::CreateSitemapRequest const& request)
      override;

  future<StatusOr<google::cloud::discoveryengine::v1::Sitemap>> CreateSitemap(
      google::longrunning::Operation const& operation) override;

  future<StatusOr<google::cloud::discoveryengine::v1::DeleteSitemapMetadata>>
  DeleteSitemap(google::cloud::discoveryengine::v1::DeleteSitemapRequest const&
                    request) override;

  StatusOr<google::longrunning::Operation> DeleteSitemap(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::DeleteSitemapRequest const& request)
      override;

  future<StatusOr<google::cloud::discoveryengine::v1::DeleteSitemapMetadata>>
  DeleteSitemap(google::longrunning::Operation const& operation) override;

  StatusOr<google::cloud::discoveryengine::v1::FetchSitemapsResponse>
  FetchSitemaps(google::cloud::discoveryengine::v1::FetchSitemapsRequest const&
                    request) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::EnableAdvancedSiteSearchResponse>>
  EnableAdvancedSiteSearch(
      google::cloud::discoveryengine::v1::EnableAdvancedSiteSearchRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> EnableAdvancedSiteSearch(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::EnableAdvancedSiteSearchRequest const&
          request) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::EnableAdvancedSiteSearchResponse>>
  EnableAdvancedSiteSearch(
      google::longrunning::Operation const& operation) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::DisableAdvancedSiteSearchResponse>>
  DisableAdvancedSiteSearch(
      google::cloud::discoveryengine::v1::
          DisableAdvancedSiteSearchRequest const& request) override;

  StatusOr<google::longrunning::Operation> DisableAdvancedSiteSearch(
      NoAwaitTag, google::cloud::discoveryengine::v1::
                      DisableAdvancedSiteSearchRequest const& request) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::DisableAdvancedSiteSearchResponse>>
  DisableAdvancedSiteSearch(
      google::longrunning::Operation const& operation) override;

  future<StatusOr<google::cloud::discoveryengine::v1::RecrawlUrisResponse>>
  RecrawlUris(google::cloud::discoveryengine::v1::RecrawlUrisRequest const&
                  request) override;

  StatusOr<google::longrunning::Operation> RecrawlUris(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::RecrawlUrisRequest const& request)
      override;

  future<StatusOr<google::cloud::discoveryengine::v1::RecrawlUrisResponse>>
  RecrawlUris(google::longrunning::Operation const& operation) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::BatchVerifyTargetSitesResponse>>
  BatchVerifyTargetSites(
      google::cloud::discoveryengine::v1::BatchVerifyTargetSitesRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> BatchVerifyTargetSites(
      NoAwaitTag,
      google::cloud::discoveryengine::v1::BatchVerifyTargetSitesRequest const&
          request) override;

  future<StatusOr<
      google::cloud::discoveryengine::v1::BatchVerifyTargetSitesResponse>>
  BatchVerifyTargetSites(
      google::longrunning::Operation const& operation) override;

  StreamRange<google::cloud::discoveryengine::v1::TargetSite>
  FetchDomainVerificationStatus(
      google::cloud::discoveryengine::v1::FetchDomainVerificationStatusRequest
          request) override;

  StreamRange<google::longrunning::Operation> ListOperations(
      google::longrunning::ListOperationsRequest request) override;

  StatusOr<google::longrunning::Operation> GetOperation(
      google::longrunning::GetOperationRequest const& request) override;

  Status CancelOperation(
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<discoveryengine_v1::SiteSearchEngineServiceConnection> child_;
};

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

/**
 * Conditionally applies the tracing decorator to the given connection.
 *
 * The connection is only decorated if tracing is enabled (as determined by the
 * connection's options).
 */
std::shared_ptr<discoveryengine_v1::SiteSearchEngineServiceConnection>
MakeSiteSearchEngineServiceTracingConnection(
    std::shared_ptr<discoveryengine_v1::SiteSearchEngineServiceConnection>
        conn);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace discoveryengine_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DISCOVERYENGINE_V1_INTERNAL_SITE_SEARCH_ENGINE_TRACING_CONNECTION_H
