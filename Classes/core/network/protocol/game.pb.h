// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game.proto

#ifndef PROTOBUF_game_2eproto__INCLUDED
#define PROTOBUF_game_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "paigow.pb.h"
#include "common.pb.h"
// @@protoc_insertion_point(includes)
namespace proto3_proto {
class Ack;
class AckDefaultTypeInternal;
extern AckDefaultTypeInternal _Ack_default_instance_;
class C2S_CreateMatch;
class C2S_CreateMatchDefaultTypeInternal;
extern C2S_CreateMatchDefaultTypeInternal _C2S_CreateMatch_default_instance_;
class C2S_Login;
class C2S_LoginDefaultTypeInternal;
extern C2S_LoginDefaultTypeInternal _C2S_Login_default_instance_;
class C2S_PG_Bet;
class C2S_PG_BetDefaultTypeInternal;
extern C2S_PG_BetDefaultTypeInternal _C2S_PG_Bet_default_instance_;
class C2S_PG_Collocation;
class C2S_PG_CollocationDefaultTypeInternal;
extern C2S_PG_CollocationDefaultTypeInternal _C2S_PG_Collocation_default_instance_;
class C2S_PG_GrabBanker;
class C2S_PG_GrabBankerDefaultTypeInternal;
extern C2S_PG_GrabBankerDefaultTypeInternal _C2S_PG_GrabBanker_default_instance_;
class C2S_PG_StartGame;
class C2S_PG_StartGameDefaultTypeInternal;
extern C2S_PG_StartGameDefaultTypeInternal _C2S_PG_StartGame_default_instance_;
class C2S_PG_Sure;
class C2S_PG_SureDefaultTypeInternal;
extern C2S_PG_SureDefaultTypeInternal _C2S_PG_Sure_default_instance_;
class Match;
class MatchDefaultTypeInternal;
extern MatchDefaultTypeInternal _Match_default_instance_;
class PaiGowCards;
class PaiGowCardsDefaultTypeInternal;
extern PaiGowCardsDefaultTypeInternal _PaiGowCards_default_instance_;
class PaiGowConfig;
class PaiGowConfigDefaultTypeInternal;
extern PaiGowConfigDefaultTypeInternal _PaiGowConfig_default_instance_;
class PaiGowPlayer;
class PaiGowPlayerDefaultTypeInternal;
extern PaiGowPlayerDefaultTypeInternal _PaiGowPlayer_default_instance_;
class PaiGowResult;
class PaiGowResultDefaultTypeInternal;
extern PaiGowResultDefaultTypeInternal _PaiGowResult_default_instance_;
class PaiGowSnapshot;
class PaiGowSnapshotDefaultTypeInternal;
extern PaiGowSnapshotDefaultTypeInternal _PaiGowSnapshot_default_instance_;
class PlayerInfo;
class PlayerInfoDefaultTypeInternal;
extern PlayerInfoDefaultTypeInternal _PlayerInfo_default_instance_;
class S2C_CreateMatch;
class S2C_CreateMatchDefaultTypeInternal;
extern S2C_CreateMatchDefaultTypeInternal _S2C_CreateMatch_default_instance_;
class S2C_Error;
class S2C_ErrorDefaultTypeInternal;
extern S2C_ErrorDefaultTypeInternal _S2C_Error_default_instance_;
class S2C_InitUserInfo;
class S2C_InitUserInfoDefaultTypeInternal;
extern S2C_InitUserInfoDefaultTypeInternal _S2C_InitUserInfo_default_instance_;
class S2C_MatchSnapshot;
class S2C_MatchSnapshotDefaultTypeInternal;
extern S2C_MatchSnapshotDefaultTypeInternal _S2C_MatchSnapshot_default_instance_;
class S2C_PG_Bet;
class S2C_PG_BetDefaultTypeInternal;
extern S2C_PG_BetDefaultTypeInternal _S2C_PG_Bet_default_instance_;
class S2C_PG_Collocation;
class S2C_PG_CollocationDefaultTypeInternal;
extern S2C_PG_CollocationDefaultTypeInternal _S2C_PG_Collocation_default_instance_;
class S2C_PG_Deal;
class S2C_PG_DealDefaultTypeInternal;
extern S2C_PG_DealDefaultTypeInternal _S2C_PG_Deal_default_instance_;
class S2C_PG_GrabBanker;
class S2C_PG_GrabBankerDefaultTypeInternal;
extern S2C_PG_GrabBankerDefaultTypeInternal _S2C_PG_GrabBanker_default_instance_;
class S2C_PG_Result;
class S2C_PG_ResultDefaultTypeInternal;
extern S2C_PG_ResultDefaultTypeInternal _S2C_PG_Result_default_instance_;
class S2C_PG_StartGame;
class S2C_PG_StartGameDefaultTypeInternal;
extern S2C_PG_StartGameDefaultTypeInternal _S2C_PG_StartGame_default_instance_;
class UserInfo;
class UserInfoDefaultTypeInternal;
extern UserInfoDefaultTypeInternal _UserInfo_default_instance_;
}  // namespace proto3_proto

namespace proto3_proto {

namespace protobuf_game_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_game_2eproto

// ===================================================================

class Match : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto3_proto.Match) */ {
 public:
  Match();
  virtual ~Match();

  Match(const Match& from);

  inline Match& operator=(const Match& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Match& default_instance();

  static inline const Match* internal_default_instance() {
    return reinterpret_cast<const Match*>(
               &_Match_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Match* other);

  // implements Message ----------------------------------------------

  inline Match* New() const PROTOBUF_FINAL { return New(NULL); }

  Match* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Match& from);
  void MergeFrom(const Match& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Match* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .proto3_proto.PlayerInfo players = 9;
  int players_size() const;
  void clear_players();
  static const int kPlayersFieldNumber = 9;
  const ::proto3_proto::PlayerInfo& players(int index) const;
  ::proto3_proto::PlayerInfo* mutable_players(int index);
  ::proto3_proto::PlayerInfo* add_players();
  ::google::protobuf::RepeatedPtrField< ::proto3_proto::PlayerInfo >*
      mutable_players();
  const ::google::protobuf::RepeatedPtrField< ::proto3_proto::PlayerInfo >&
      players() const;

  // .proto3_proto.PaiGowConfig paigow = 8;
  bool has_paigow() const;
  void clear_paigow();
  static const int kPaigowFieldNumber = 8;
  const ::proto3_proto::PaiGowConfig& paigow() const;
  ::proto3_proto::PaiGowConfig* mutable_paigow();
  ::proto3_proto::PaiGowConfig* release_paigow();
  void set_allocated_paigow(::proto3_proto::PaiGowConfig* paigow);

  // int32 room_id = 1;
  void clear_room_id();
  static const int kRoomIdFieldNumber = 1;
  ::google::protobuf::int32 room_id() const;
  void set_room_id(::google::protobuf::int32 value);

  // int32 type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::google::protobuf::int32 type() const;
  void set_type(::google::protobuf::int32 value);

  // int64 time = 3;
  void clear_time();
  static const int kTimeFieldNumber = 3;
  ::google::protobuf::int64 time() const;
  void set_time(::google::protobuf::int64 value);

  // int32 number = 4;
  void clear_number();
  static const int kNumberFieldNumber = 4;
  ::google::protobuf::int32 number() const;
  void set_number(::google::protobuf::int32 value);

  // int32 cost = 5;
  void clear_cost();
  static const int kCostFieldNumber = 5;
  ::google::protobuf::int32 cost() const;
  void set_cost(::google::protobuf::int32 value);

  // int32 state = 6;
  void clear_state();
  static const int kStateFieldNumber = 6;
  ::google::protobuf::int32 state() const;
  void set_state(::google::protobuf::int32 value);

  // int32 round = 7;
  void clear_round();
  static const int kRoundFieldNumber = 7;
  ::google::protobuf::int32 round() const;
  void set_round(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto3_proto.Match)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::proto3_proto::PlayerInfo > players_;
  ::proto3_proto::PaiGowConfig* paigow_;
  ::google::protobuf::int32 room_id_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int64 time_;
  ::google::protobuf::int32 number_;
  ::google::protobuf::int32 cost_;
  ::google::protobuf::int32 state_;
  ::google::protobuf::int32 round_;
  mutable int _cached_size_;
  friend struct protobuf_game_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class C2S_CreateMatch : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto3_proto.C2S_CreateMatch) */ {
 public:
  C2S_CreateMatch();
  virtual ~C2S_CreateMatch();

  C2S_CreateMatch(const C2S_CreateMatch& from);

  inline C2S_CreateMatch& operator=(const C2S_CreateMatch& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const C2S_CreateMatch& default_instance();

  static inline const C2S_CreateMatch* internal_default_instance() {
    return reinterpret_cast<const C2S_CreateMatch*>(
               &_C2S_CreateMatch_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(C2S_CreateMatch* other);

  // implements Message ----------------------------------------------

  inline C2S_CreateMatch* New() const PROTOBUF_FINAL { return New(NULL); }

  C2S_CreateMatch* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const C2S_CreateMatch& from);
  void MergeFrom(const C2S_CreateMatch& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(C2S_CreateMatch* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .proto3_proto.PaiGowConfig paigow = 5;
  bool has_paigow() const;
  void clear_paigow();
  static const int kPaigowFieldNumber = 5;
  const ::proto3_proto::PaiGowConfig& paigow() const;
  ::proto3_proto::PaiGowConfig* mutable_paigow();
  ::proto3_proto::PaiGowConfig* release_paigow();
  void set_allocated_paigow(::proto3_proto::PaiGowConfig* paigow);

  // bool for_other = 1;
  void clear_for_other();
  static const int kForOtherFieldNumber = 1;
  bool for_other() const;
  void set_for_other(bool value);

  // int32 type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::google::protobuf::int32 type() const;
  void set_type(::google::protobuf::int32 value);

  // int32 number = 3;
  void clear_number();
  static const int kNumberFieldNumber = 3;
  ::google::protobuf::int32 number() const;
  void set_number(::google::protobuf::int32 value);

  // int32 cost = 4;
  void clear_cost();
  static const int kCostFieldNumber = 4;
  ::google::protobuf::int32 cost() const;
  void set_cost(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto3_proto.C2S_CreateMatch)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::proto3_proto::PaiGowConfig* paigow_;
  bool for_other_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 number_;
  ::google::protobuf::int32 cost_;
  mutable int _cached_size_;
  friend struct protobuf_game_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class S2C_CreateMatch : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto3_proto.S2C_CreateMatch) */ {
 public:
  S2C_CreateMatch();
  virtual ~S2C_CreateMatch();

  S2C_CreateMatch(const S2C_CreateMatch& from);

  inline S2C_CreateMatch& operator=(const S2C_CreateMatch& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const S2C_CreateMatch& default_instance();

  static inline const S2C_CreateMatch* internal_default_instance() {
    return reinterpret_cast<const S2C_CreateMatch*>(
               &_S2C_CreateMatch_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(S2C_CreateMatch* other);

  // implements Message ----------------------------------------------

  inline S2C_CreateMatch* New() const PROTOBUF_FINAL { return New(NULL); }

  S2C_CreateMatch* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const S2C_CreateMatch& from);
  void MergeFrom(const S2C_CreateMatch& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(S2C_CreateMatch* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .proto3_proto.Match match = 3;
  bool has_match() const;
  void clear_match();
  static const int kMatchFieldNumber = 3;
  const ::proto3_proto::Match& match() const;
  ::proto3_proto::Match* mutable_match();
  ::proto3_proto::Match* release_match();
  void set_allocated_match(::proto3_proto::Match* match);

  // int32 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // bool for_other = 2;
  void clear_for_other();
  static const int kForOtherFieldNumber = 2;
  bool for_other() const;
  void set_for_other(bool value);

  // @@protoc_insertion_point(class_scope:proto3_proto.S2C_CreateMatch)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::proto3_proto::Match* match_;
  ::google::protobuf::int32 code_;
  bool for_other_;
  mutable int _cached_size_;
  friend struct protobuf_game_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class S2C_MatchSnapshot : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proto3_proto.S2C_MatchSnapshot) */ {
 public:
  S2C_MatchSnapshot();
  virtual ~S2C_MatchSnapshot();

  S2C_MatchSnapshot(const S2C_MatchSnapshot& from);

  inline S2C_MatchSnapshot& operator=(const S2C_MatchSnapshot& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const S2C_MatchSnapshot& default_instance();

  static inline const S2C_MatchSnapshot* internal_default_instance() {
    return reinterpret_cast<const S2C_MatchSnapshot*>(
               &_S2C_MatchSnapshot_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(S2C_MatchSnapshot* other);

  // implements Message ----------------------------------------------

  inline S2C_MatchSnapshot* New() const PROTOBUF_FINAL { return New(NULL); }

  S2C_MatchSnapshot* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const S2C_MatchSnapshot& from);
  void MergeFrom(const S2C_MatchSnapshot& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(S2C_MatchSnapshot* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .proto3_proto.Match match = 1;
  bool has_match() const;
  void clear_match();
  static const int kMatchFieldNumber = 1;
  const ::proto3_proto::Match& match() const;
  ::proto3_proto::Match* mutable_match();
  ::proto3_proto::Match* release_match();
  void set_allocated_match(::proto3_proto::Match* match);

  // .proto3_proto.PaiGowSnapshot paigpow = 2;
  bool has_paigpow() const;
  void clear_paigpow();
  static const int kPaigpowFieldNumber = 2;
  const ::proto3_proto::PaiGowSnapshot& paigpow() const;
  ::proto3_proto::PaiGowSnapshot* mutable_paigpow();
  ::proto3_proto::PaiGowSnapshot* release_paigpow();
  void set_allocated_paigpow(::proto3_proto::PaiGowSnapshot* paigpow);

  // @@protoc_insertion_point(class_scope:proto3_proto.S2C_MatchSnapshot)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::proto3_proto::Match* match_;
  ::proto3_proto::PaiGowSnapshot* paigpow_;
  mutable int _cached_size_;
  friend struct protobuf_game_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Match

// int32 room_id = 1;
inline void Match::clear_room_id() {
  room_id_ = 0;
}
inline ::google::protobuf::int32 Match::room_id() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.room_id)
  return room_id_;
}
inline void Match::set_room_id(::google::protobuf::int32 value) {
  
  room_id_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.room_id)
}

// int32 type = 2;
inline void Match::clear_type() {
  type_ = 0;
}
inline ::google::protobuf::int32 Match::type() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.type)
  return type_;
}
inline void Match::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.type)
}

// int64 time = 3;
inline void Match::clear_time() {
  time_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Match::time() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.time)
  return time_;
}
inline void Match::set_time(::google::protobuf::int64 value) {
  
  time_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.time)
}

// int32 number = 4;
inline void Match::clear_number() {
  number_ = 0;
}
inline ::google::protobuf::int32 Match::number() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.number)
  return number_;
}
inline void Match::set_number(::google::protobuf::int32 value) {
  
  number_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.number)
}

// int32 cost = 5;
inline void Match::clear_cost() {
  cost_ = 0;
}
inline ::google::protobuf::int32 Match::cost() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.cost)
  return cost_;
}
inline void Match::set_cost(::google::protobuf::int32 value) {
  
  cost_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.cost)
}

// int32 state = 6;
inline void Match::clear_state() {
  state_ = 0;
}
inline ::google::protobuf::int32 Match::state() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.state)
  return state_;
}
inline void Match::set_state(::google::protobuf::int32 value) {
  
  state_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.state)
}

// int32 round = 7;
inline void Match::clear_round() {
  round_ = 0;
}
inline ::google::protobuf::int32 Match::round() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.round)
  return round_;
}
inline void Match::set_round(::google::protobuf::int32 value) {
  
  round_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.Match.round)
}

// .proto3_proto.PaiGowConfig paigow = 8;
inline bool Match::has_paigow() const {
  return this != internal_default_instance() && paigow_ != NULL;
}
inline void Match::clear_paigow() {
  if (GetArenaNoVirtual() == NULL && paigow_ != NULL) delete paigow_;
  paigow_ = NULL;
}
inline const ::proto3_proto::PaiGowConfig& Match::paigow() const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.paigow)
  return paigow_ != NULL ? *paigow_
                         : *::proto3_proto::PaiGowConfig::internal_default_instance();
}
inline ::proto3_proto::PaiGowConfig* Match::mutable_paigow() {
  
  if (paigow_ == NULL) {
    paigow_ = new ::proto3_proto::PaiGowConfig;
  }
  // @@protoc_insertion_point(field_mutable:proto3_proto.Match.paigow)
  return paigow_;
}
inline ::proto3_proto::PaiGowConfig* Match::release_paigow() {
  // @@protoc_insertion_point(field_release:proto3_proto.Match.paigow)
  
  ::proto3_proto::PaiGowConfig* temp = paigow_;
  paigow_ = NULL;
  return temp;
}
inline void Match::set_allocated_paigow(::proto3_proto::PaiGowConfig* paigow) {
  delete paigow_;
  paigow_ = paigow;
  if (paigow) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:proto3_proto.Match.paigow)
}

// repeated .proto3_proto.PlayerInfo players = 9;
inline int Match::players_size() const {
  return players_.size();
}
inline void Match::clear_players() {
  players_.Clear();
}
inline const ::proto3_proto::PlayerInfo& Match::players(int index) const {
  // @@protoc_insertion_point(field_get:proto3_proto.Match.players)
  return players_.Get(index);
}
inline ::proto3_proto::PlayerInfo* Match::mutable_players(int index) {
  // @@protoc_insertion_point(field_mutable:proto3_proto.Match.players)
  return players_.Mutable(index);
}
inline ::proto3_proto::PlayerInfo* Match::add_players() {
  // @@protoc_insertion_point(field_add:proto3_proto.Match.players)
  return players_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::proto3_proto::PlayerInfo >*
Match::mutable_players() {
  // @@protoc_insertion_point(field_mutable_list:proto3_proto.Match.players)
  return &players_;
}
inline const ::google::protobuf::RepeatedPtrField< ::proto3_proto::PlayerInfo >&
Match::players() const {
  // @@protoc_insertion_point(field_list:proto3_proto.Match.players)
  return players_;
}

// -------------------------------------------------------------------

// C2S_CreateMatch

// bool for_other = 1;
inline void C2S_CreateMatch::clear_for_other() {
  for_other_ = false;
}
inline bool C2S_CreateMatch::for_other() const {
  // @@protoc_insertion_point(field_get:proto3_proto.C2S_CreateMatch.for_other)
  return for_other_;
}
inline void C2S_CreateMatch::set_for_other(bool value) {
  
  for_other_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.C2S_CreateMatch.for_other)
}

// int32 type = 2;
inline void C2S_CreateMatch::clear_type() {
  type_ = 0;
}
inline ::google::protobuf::int32 C2S_CreateMatch::type() const {
  // @@protoc_insertion_point(field_get:proto3_proto.C2S_CreateMatch.type)
  return type_;
}
inline void C2S_CreateMatch::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.C2S_CreateMatch.type)
}

// int32 number = 3;
inline void C2S_CreateMatch::clear_number() {
  number_ = 0;
}
inline ::google::protobuf::int32 C2S_CreateMatch::number() const {
  // @@protoc_insertion_point(field_get:proto3_proto.C2S_CreateMatch.number)
  return number_;
}
inline void C2S_CreateMatch::set_number(::google::protobuf::int32 value) {
  
  number_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.C2S_CreateMatch.number)
}

// int32 cost = 4;
inline void C2S_CreateMatch::clear_cost() {
  cost_ = 0;
}
inline ::google::protobuf::int32 C2S_CreateMatch::cost() const {
  // @@protoc_insertion_point(field_get:proto3_proto.C2S_CreateMatch.cost)
  return cost_;
}
inline void C2S_CreateMatch::set_cost(::google::protobuf::int32 value) {
  
  cost_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.C2S_CreateMatch.cost)
}

// .proto3_proto.PaiGowConfig paigow = 5;
inline bool C2S_CreateMatch::has_paigow() const {
  return this != internal_default_instance() && paigow_ != NULL;
}
inline void C2S_CreateMatch::clear_paigow() {
  if (GetArenaNoVirtual() == NULL && paigow_ != NULL) delete paigow_;
  paigow_ = NULL;
}
inline const ::proto3_proto::PaiGowConfig& C2S_CreateMatch::paigow() const {
  // @@protoc_insertion_point(field_get:proto3_proto.C2S_CreateMatch.paigow)
  return paigow_ != NULL ? *paigow_
                         : *::proto3_proto::PaiGowConfig::internal_default_instance();
}
inline ::proto3_proto::PaiGowConfig* C2S_CreateMatch::mutable_paigow() {
  
  if (paigow_ == NULL) {
    paigow_ = new ::proto3_proto::PaiGowConfig;
  }
  // @@protoc_insertion_point(field_mutable:proto3_proto.C2S_CreateMatch.paigow)
  return paigow_;
}
inline ::proto3_proto::PaiGowConfig* C2S_CreateMatch::release_paigow() {
  // @@protoc_insertion_point(field_release:proto3_proto.C2S_CreateMatch.paigow)
  
  ::proto3_proto::PaiGowConfig* temp = paigow_;
  paigow_ = NULL;
  return temp;
}
inline void C2S_CreateMatch::set_allocated_paigow(::proto3_proto::PaiGowConfig* paigow) {
  delete paigow_;
  paigow_ = paigow;
  if (paigow) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:proto3_proto.C2S_CreateMatch.paigow)
}

// -------------------------------------------------------------------

// S2C_CreateMatch

// int32 code = 1;
inline void S2C_CreateMatch::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 S2C_CreateMatch::code() const {
  // @@protoc_insertion_point(field_get:proto3_proto.S2C_CreateMatch.code)
  return code_;
}
inline void S2C_CreateMatch::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.S2C_CreateMatch.code)
}

// bool for_other = 2;
inline void S2C_CreateMatch::clear_for_other() {
  for_other_ = false;
}
inline bool S2C_CreateMatch::for_other() const {
  // @@protoc_insertion_point(field_get:proto3_proto.S2C_CreateMatch.for_other)
  return for_other_;
}
inline void S2C_CreateMatch::set_for_other(bool value) {
  
  for_other_ = value;
  // @@protoc_insertion_point(field_set:proto3_proto.S2C_CreateMatch.for_other)
}

// .proto3_proto.Match match = 3;
inline bool S2C_CreateMatch::has_match() const {
  return this != internal_default_instance() && match_ != NULL;
}
inline void S2C_CreateMatch::clear_match() {
  if (GetArenaNoVirtual() == NULL && match_ != NULL) delete match_;
  match_ = NULL;
}
inline const ::proto3_proto::Match& S2C_CreateMatch::match() const {
  // @@protoc_insertion_point(field_get:proto3_proto.S2C_CreateMatch.match)
  return match_ != NULL ? *match_
                         : *::proto3_proto::Match::internal_default_instance();
}
inline ::proto3_proto::Match* S2C_CreateMatch::mutable_match() {
  
  if (match_ == NULL) {
    match_ = new ::proto3_proto::Match;
  }
  // @@protoc_insertion_point(field_mutable:proto3_proto.S2C_CreateMatch.match)
  return match_;
}
inline ::proto3_proto::Match* S2C_CreateMatch::release_match() {
  // @@protoc_insertion_point(field_release:proto3_proto.S2C_CreateMatch.match)
  
  ::proto3_proto::Match* temp = match_;
  match_ = NULL;
  return temp;
}
inline void S2C_CreateMatch::set_allocated_match(::proto3_proto::Match* match) {
  delete match_;
  match_ = match;
  if (match) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:proto3_proto.S2C_CreateMatch.match)
}

// -------------------------------------------------------------------

// S2C_MatchSnapshot

// .proto3_proto.Match match = 1;
inline bool S2C_MatchSnapshot::has_match() const {
  return this != internal_default_instance() && match_ != NULL;
}
inline void S2C_MatchSnapshot::clear_match() {
  if (GetArenaNoVirtual() == NULL && match_ != NULL) delete match_;
  match_ = NULL;
}
inline const ::proto3_proto::Match& S2C_MatchSnapshot::match() const {
  // @@protoc_insertion_point(field_get:proto3_proto.S2C_MatchSnapshot.match)
  return match_ != NULL ? *match_
                         : *::proto3_proto::Match::internal_default_instance();
}
inline ::proto3_proto::Match* S2C_MatchSnapshot::mutable_match() {
  
  if (match_ == NULL) {
    match_ = new ::proto3_proto::Match;
  }
  // @@protoc_insertion_point(field_mutable:proto3_proto.S2C_MatchSnapshot.match)
  return match_;
}
inline ::proto3_proto::Match* S2C_MatchSnapshot::release_match() {
  // @@protoc_insertion_point(field_release:proto3_proto.S2C_MatchSnapshot.match)
  
  ::proto3_proto::Match* temp = match_;
  match_ = NULL;
  return temp;
}
inline void S2C_MatchSnapshot::set_allocated_match(::proto3_proto::Match* match) {
  delete match_;
  match_ = match;
  if (match) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:proto3_proto.S2C_MatchSnapshot.match)
}

// .proto3_proto.PaiGowSnapshot paigpow = 2;
inline bool S2C_MatchSnapshot::has_paigpow() const {
  return this != internal_default_instance() && paigpow_ != NULL;
}
inline void S2C_MatchSnapshot::clear_paigpow() {
  if (GetArenaNoVirtual() == NULL && paigpow_ != NULL) delete paigpow_;
  paigpow_ = NULL;
}
inline const ::proto3_proto::PaiGowSnapshot& S2C_MatchSnapshot::paigpow() const {
  // @@protoc_insertion_point(field_get:proto3_proto.S2C_MatchSnapshot.paigpow)
  return paigpow_ != NULL ? *paigpow_
                         : *::proto3_proto::PaiGowSnapshot::internal_default_instance();
}
inline ::proto3_proto::PaiGowSnapshot* S2C_MatchSnapshot::mutable_paigpow() {
  
  if (paigpow_ == NULL) {
    paigpow_ = new ::proto3_proto::PaiGowSnapshot;
  }
  // @@protoc_insertion_point(field_mutable:proto3_proto.S2C_MatchSnapshot.paigpow)
  return paigpow_;
}
inline ::proto3_proto::PaiGowSnapshot* S2C_MatchSnapshot::release_paigpow() {
  // @@protoc_insertion_point(field_release:proto3_proto.S2C_MatchSnapshot.paigpow)
  
  ::proto3_proto::PaiGowSnapshot* temp = paigpow_;
  paigpow_ = NULL;
  return temp;
}
inline void S2C_MatchSnapshot::set_allocated_paigpow(::proto3_proto::PaiGowSnapshot* paigpow) {
  delete paigpow_;
  paigpow_ = paigpow;
  if (paigpow) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:proto3_proto.S2C_MatchSnapshot.paigpow)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace proto3_proto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_game_2eproto__INCLUDED
