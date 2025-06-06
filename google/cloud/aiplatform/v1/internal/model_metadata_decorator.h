// Copyright 2023 Google LLC
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
// source: google/cloud/aiplatform/v1/model_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_MODEL_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_MODEL_METADATA_DECORATOR_H

#include "google/cloud/aiplatform/v1/internal/model_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ModelServiceMetadata : public ModelServiceStub {
 public:
  ~ModelServiceMetadata() override = default;
  ModelServiceMetadata(std::shared_ptr<ModelServiceStub> child,
                       std::multimap<std::string, std::string> fixed_metadata,
                       std::string api_client_header = "");

  future<StatusOr<google::longrunning::Operation>> AsyncUploadModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UploadModelRequest const& request)
      override;

  StatusOr<google::longrunning::Operation> UploadModel(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::UploadModelRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::Model> GetModel(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetModelRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::ListModelsResponse> ListModels(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListModelsRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::ListModelVersionsResponse>
  ListModelVersions(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListModelVersionsRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListModelVersionCheckpointsResponse>
  ListModelVersionCheckpoints(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListModelVersionCheckpointsRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::Model> UpdateModel(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::UpdateModelRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateExplanationDataset(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UpdateExplanationDatasetRequest const&
          request) override;

  StatusOr<google::longrunning::Operation> UpdateExplanationDataset(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::UpdateExplanationDatasetRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteModelRequest const& request)
      override;

  StatusOr<google::longrunning::Operation> DeleteModel(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::DeleteModelRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteModelVersion(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteModelVersionRequest const& request)
      override;

  StatusOr<google::longrunning::Operation> DeleteModelVersion(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::DeleteModelVersionRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::Model> MergeVersionAliases(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::MergeVersionAliasesRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncExportModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::ExportModelRequest const& request)
      override;

  StatusOr<google::longrunning::Operation> ExportModel(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::ExportModelRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCopyModel(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::CopyModelRequest const& request) override;

  StatusOr<google::longrunning::Operation> CopyModel(
      grpc::ClientContext& context, Options options,
      google::cloud::aiplatform::v1::CopyModelRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::ModelEvaluation>
  ImportModelEvaluation(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ImportModelEvaluationRequest const&
          request) override;

  StatusOr<
      google::cloud::aiplatform::v1::BatchImportModelEvaluationSlicesResponse>
  BatchImportModelEvaluationSlices(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::
          BatchImportModelEvaluationSlicesRequest const& request) override;

  StatusOr<
      google::cloud::aiplatform::v1::BatchImportEvaluatedAnnotationsResponse>
  BatchImportEvaluatedAnnotations(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::
          BatchImportEvaluatedAnnotationsRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::ModelEvaluation> GetModelEvaluation(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetModelEvaluationRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListModelEvaluationsResponse>
  ListModelEvaluations(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListModelEvaluationsRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ModelEvaluationSlice>
  GetModelEvaluationSlice(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetModelEvaluationSliceRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::ListModelEvaluationSlicesResponse>
  ListModelEvaluationSlices(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListModelEvaluationSlicesRequest const&
          request) override;

  StatusOr<google::cloud::location::ListLocationsResponse> ListLocations(
      grpc::ClientContext& context, Options const& options,
      google::cloud::location::ListLocationsRequest const& request) override;

  StatusOr<google::cloud::location::Location> GetLocation(
      grpc::ClientContext& context, Options const& options,
      google::cloud::location::GetLocationRequest const& request) override;

  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext& context, Options const& options,
      google::iam::v1::SetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext& context, Options const& options,
      google::iam::v1::GetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      grpc::ClientContext& context, Options const& options,
      google::iam::v1::TestIamPermissionsRequest const& request) override;

  StatusOr<google::longrunning::ListOperationsResponse> ListOperations(
      grpc::ClientContext& context, Options const& options,
      google::longrunning::ListOperationsRequest const& request) override;

  StatusOr<google::longrunning::Operation> GetOperation(
      grpc::ClientContext& context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  Status DeleteOperation(
      grpc::ClientContext& context, Options const& options,
      google::longrunning::DeleteOperationRequest const& request) override;

  Status CancelOperation(
      grpc::ClientContext& context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

  StatusOr<google::longrunning::Operation> WaitOperation(
      grpc::ClientContext& context, Options const& options,
      google::longrunning::WaitOperationRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context, Options const& options,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context, Options const& options);

  std::shared_ptr<ModelServiceStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_MODEL_METADATA_DECORATOR_H
