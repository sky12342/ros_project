// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: publish_info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_publish_5finfo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_publish_5finfo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_publish_5finfo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_publish_5finfo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_publish_5finfo_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_publish_5finfo_2eproto_metadata_getter(int index);
namespace Destination {
namespace site {
class PublishInfo;
struct PublishInfoDefaultTypeInternal;
extern PublishInfoDefaultTypeInternal _PublishInfo_default_instance_;
}  // namespace site
}  // namespace Destination
PROTOBUF_NAMESPACE_OPEN
template<> ::Destination::site::PublishInfo* Arena::CreateMaybeMessage<::Destination::site::PublishInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Destination {
namespace site {

// ===================================================================

class PublishInfo PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Destination.site.PublishInfo) */ {
 public:
  inline PublishInfo() : PublishInfo(nullptr) {}
  virtual ~PublishInfo();
  explicit constexpr PublishInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PublishInfo(const PublishInfo& from);
  PublishInfo(PublishInfo&& from) noexcept
    : PublishInfo() {
    *this = ::std::move(from);
  }

  inline PublishInfo& operator=(const PublishInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PublishInfo& operator=(PublishInfo&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PublishInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const PublishInfo* internal_default_instance() {
    return reinterpret_cast<const PublishInfo*>(
               &_PublishInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PublishInfo& a, PublishInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(PublishInfo* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PublishInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PublishInfo* New() const final {
    return CreateMaybeMessage<PublishInfo>(nullptr);
  }

  PublishInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PublishInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PublishInfo& from);
  void MergeFrom(const PublishInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PublishInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Destination.site.PublishInfo";
  }
  protected:
  explicit PublishInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_publish_5finfo_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDestinationXFieldNumber = 1,
    kDestinationYFieldNumber = 2,
  };
  // int32 destination_x = 1;
  void clear_destination_x();
  ::PROTOBUF_NAMESPACE_ID::int32 destination_x() const;
  void set_destination_x(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_destination_x() const;
  void _internal_set_destination_x(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 destination_y = 2;
  void clear_destination_y();
  ::PROTOBUF_NAMESPACE_ID::int32 destination_y() const;
  void set_destination_y(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_destination_y() const;
  void _internal_set_destination_y(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:Destination.site.PublishInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 destination_x_;
  ::PROTOBUF_NAMESPACE_ID::int32 destination_y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_publish_5finfo_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PublishInfo

// int32 destination_x = 1;
inline void PublishInfo::clear_destination_x() {
  destination_x_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PublishInfo::_internal_destination_x() const {
  return destination_x_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PublishInfo::destination_x() const {
  // @@protoc_insertion_point(field_get:Destination.site.PublishInfo.destination_x)
  return _internal_destination_x();
}
inline void PublishInfo::_internal_set_destination_x(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  destination_x_ = value;
}
inline void PublishInfo::set_destination_x(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_destination_x(value);
  // @@protoc_insertion_point(field_set:Destination.site.PublishInfo.destination_x)
}

// int32 destination_y = 2;
inline void PublishInfo::clear_destination_y() {
  destination_y_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PublishInfo::_internal_destination_y() const {
  return destination_y_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 PublishInfo::destination_y() const {
  // @@protoc_insertion_point(field_get:Destination.site.PublishInfo.destination_y)
  return _internal_destination_y();
}
inline void PublishInfo::_internal_set_destination_y(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  destination_y_ = value;
}
inline void PublishInfo::set_destination_y(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_destination_y(value);
  // @@protoc_insertion_point(field_set:Destination.site.PublishInfo.destination_y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace site
}  // namespace Destination

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_publish_5finfo_2eproto
