// Copyright 2022 Google LLC
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
// source: google/cloud/dialogflow/v2/conversation.proto

#include "google/cloud/dialogflow_es/conversations_client.h"
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConversationsClient::ConversationsClient(
    std::shared_ptr<ConversationsConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
ConversationsClient::~ConversationsClient() = default;

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::CreateConversation(
    std::string const& parent,
    google::cloud::dialogflow::v2::Conversation const& conversation,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::CreateConversationRequest request;
  request.set_parent(parent);
  *request.mutable_conversation() = conversation;
  return connection_->CreateConversation(request);
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::CreateConversation(
    google::cloud::dialogflow::v2::CreateConversationRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateConversation(request);
}

StreamRange<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::ListConversations(std::string const& parent,
                                       Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::ListConversationsRequest request;
  request.set_parent(parent);
  return connection_->ListConversations(request);
}

StreamRange<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::ListConversations(
    google::cloud::dialogflow::v2::ListConversationsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListConversations(std::move(request));
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::GetConversation(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::GetConversationRequest request;
  request.set_name(name);
  return connection_->GetConversation(request);
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::GetConversation(
    google::cloud::dialogflow::v2::GetConversationRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetConversation(request);
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::CompleteConversation(std::string const& name,
                                          Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::CompleteConversationRequest request;
  request.set_name(name);
  return connection_->CompleteConversation(request);
}

StatusOr<google::cloud::dialogflow::v2::Conversation>
ConversationsClient::CompleteConversation(
    google::cloud::dialogflow::v2::CompleteConversationRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CompleteConversation(request);
}

StatusOr<google::cloud::dialogflow::v2::IngestContextReferencesResponse>
ConversationsClient::IngestContextReferences(
    std::string const& conversation,
    std::map<std::string, google::cloud::dialogflow::v2::Conversation::
                              ContextReference> const& context_references,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::IngestContextReferencesRequest request;
  request.set_conversation(conversation);
  *request.mutable_context_references() = {context_references.begin(),
                                           context_references.end()};
  return connection_->IngestContextReferences(request);
}

StatusOr<google::cloud::dialogflow::v2::IngestContextReferencesResponse>
ConversationsClient::IngestContextReferences(
    google::cloud::dialogflow::v2::IngestContextReferencesRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->IngestContextReferences(request);
}

StreamRange<google::cloud::dialogflow::v2::Message>
ConversationsClient::ListMessages(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::ListMessagesRequest request;
  request.set_parent(parent);
  return connection_->ListMessages(request);
}

StreamRange<google::cloud::dialogflow::v2::Message>
ConversationsClient::ListMessages(
    google::cloud::dialogflow::v2::ListMessagesRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListMessages(std::move(request));
}

StatusOr<google::cloud::dialogflow::v2::SuggestConversationSummaryResponse>
ConversationsClient::SuggestConversationSummary(std::string const& conversation,
                                                Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::SuggestConversationSummaryRequest request;
  request.set_conversation(conversation);
  return connection_->SuggestConversationSummary(request);
}

StatusOr<google::cloud::dialogflow::v2::SuggestConversationSummaryResponse>
ConversationsClient::SuggestConversationSummary(
    google::cloud::dialogflow::v2::SuggestConversationSummaryRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SuggestConversationSummary(request);
}

StatusOr<google::cloud::dialogflow::v2::GenerateStatelessSummaryResponse>
ConversationsClient::GenerateStatelessSummary(
    google::cloud::dialogflow::v2::GenerateStatelessSummaryRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GenerateStatelessSummary(request);
}

StatusOr<google::cloud::dialogflow::v2::GenerateStatelessSuggestionResponse>
ConversationsClient::GenerateStatelessSuggestion(
    google::cloud::dialogflow::v2::GenerateStatelessSuggestionRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GenerateStatelessSuggestion(request);
}

StatusOr<google::cloud::dialogflow::v2::SearchKnowledgeResponse>
ConversationsClient::SearchKnowledge(
    google::cloud::dialogflow::v2::SearchKnowledgeRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SearchKnowledge(request);
}

StatusOr<google::cloud::dialogflow::v2::GenerateSuggestionsResponse>
ConversationsClient::GenerateSuggestions(std::string const& conversation,
                                         Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::v2::GenerateSuggestionsRequest request;
  request.set_conversation(conversation);
  return connection_->GenerateSuggestions(request);
}

StatusOr<google::cloud::dialogflow::v2::GenerateSuggestionsResponse>
ConversationsClient::GenerateSuggestions(
    google::cloud::dialogflow::v2::GenerateSuggestionsRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GenerateSuggestions(request);
}

StreamRange<google::cloud::location::Location>
ConversationsClient::ListLocations(
    google::cloud::location::ListLocationsRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListLocations(std::move(request));
}

StatusOr<google::cloud::location::Location> ConversationsClient::GetLocation(
    google::cloud::location::GetLocationRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetLocation(request);
}

StreamRange<google::longrunning::Operation> ConversationsClient::ListOperations(
    std::string const& name, std::string const& filter, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::longrunning::ListOperationsRequest request;
  request.set_name(name);
  request.set_filter(filter);
  return connection_->ListOperations(request);
}

StreamRange<google::longrunning::Operation> ConversationsClient::ListOperations(
    google::longrunning::ListOperationsRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListOperations(std::move(request));
}

StatusOr<google::longrunning::Operation> ConversationsClient::GetOperation(
    std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::longrunning::GetOperationRequest request;
  request.set_name(name);
  return connection_->GetOperation(request);
}

StatusOr<google::longrunning::Operation> ConversationsClient::GetOperation(
    google::longrunning::GetOperationRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetOperation(request);
}

Status ConversationsClient::CancelOperation(std::string const& name,
                                            Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::longrunning::CancelOperationRequest request;
  request.set_name(name);
  return connection_->CancelOperation(request);
}

Status ConversationsClient::CancelOperation(
    google::longrunning::CancelOperationRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CancelOperation(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google
