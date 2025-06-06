// Copyright 2025 Google LLC
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
// source: google/cloud/chronicle/v1/entity.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHRONICLE_V1_INTERNAL_ENTITY_TRACING_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHRONICLE_V1_INTERNAL_ENTITY_TRACING_CONNECTION_H

#include "google/cloud/chronicle/v1/entity_connection.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace chronicle_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

class EntityServiceTracingConnection
    : public chronicle_v1::EntityServiceConnection {
 public:
  ~EntityServiceTracingConnection() override = default;

  explicit EntityServiceTracingConnection(
      std::shared_ptr<chronicle_v1::EntityServiceConnection> child);

  Options options() override { return child_->options(); }

  StatusOr<google::cloud::chronicle::v1::Watchlist> GetWatchlist(
      google::cloud::chronicle::v1::GetWatchlistRequest const& request)
      override;

  StreamRange<google::cloud::chronicle::v1::Watchlist> ListWatchlists(
      google::cloud::chronicle::v1::ListWatchlistsRequest request) override;

  StatusOr<google::cloud::chronicle::v1::Watchlist> CreateWatchlist(
      google::cloud::chronicle::v1::CreateWatchlistRequest const& request)
      override;

  StatusOr<google::cloud::chronicle::v1::Watchlist> UpdateWatchlist(
      google::cloud::chronicle::v1::UpdateWatchlistRequest const& request)
      override;

  Status DeleteWatchlist(
      google::cloud::chronicle::v1::DeleteWatchlistRequest const& request)
      override;

  StreamRange<google::longrunning::Operation> ListOperations(
      google::longrunning::ListOperationsRequest request) override;

  StatusOr<google::longrunning::Operation> GetOperation(
      google::longrunning::GetOperationRequest const& request) override;

  Status DeleteOperation(
      google::longrunning::DeleteOperationRequest const& request) override;

  Status CancelOperation(
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<chronicle_v1::EntityServiceConnection> child_;
};

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

/**
 * Conditionally applies the tracing decorator to the given connection.
 *
 * The connection is only decorated if tracing is enabled (as determined by the
 * connection's options).
 */
std::shared_ptr<chronicle_v1::EntityServiceConnection>
MakeEntityServiceTracingConnection(
    std::shared_ptr<chronicle_v1::EntityServiceConnection> conn);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace chronicle_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHRONICLE_V1_INTERNAL_ENTITY_TRACING_CONNECTION_H
