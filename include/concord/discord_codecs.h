#ifndef DISCORD_CODECS_H
#define DISCORD_CODECS_H
#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>
#include "carray.h"
#include "cog-utils.h"
#include "types.h"
struct strings { int size;
    char * * array;
int realsize; };
struct json_values { int size;
    json_char * * array;
int realsize; };
struct snowflakes { int size;
    u64snowflake *array;
int realsize; };
struct bitmasks { int size;
    u64bitmask *array;
int realsize; };
struct integers { int size;
    int *array;
int realsize; };
#define DISCORD_APPLICATION_GATEWAY_PRESENCE 1 << 12
#define DISCORD_APPLICATION_GATEWAY_PRESENCE_LIMITED 1 << 13
#define DISCORD_APPLICATION_GATEWAY_GUILD_MEMBERS 1 << 14
#define DISCORD_APPLICATION_GATEWAY_GUILD_MEMBERS_LIMITED 1 << 15
#define DISCORD_APPLICATION_VERIFICATION_PENDING_GUILD_LIMIT 1 << 16
#define DISCORD_APPLICATION_EMBEDDED 1 << 17
#define DISCORD_APPLICATION_GATEWAY_MESSAGE_CONTENT 1 << 18
#define DISCORD_APPLICATION_GATEWAY_MESSAGE_CONTENT_LIMITED 1 << 19
struct discord_application {
    u64snowflake id;
    char * name;
    char * icon;
    char * description;
 
    struct strings * rpc_origins;
 
    bool bot_public;
    bool bot_require_code_grant;
    char * terms_of_service_url;
    char * privacy_policy_url;
 
    struct discord_user * owner;
 
    char * summary;
    char * verify_key;
 
    struct discord_team * team;
 
    u64snowflake guild_id;
    u64snowflake primary_sku_id;
    char * slug;
    char * cover_image;
    u64bitmask flags;
};
struct discord_install_params {
    struct strings * scopes;
    u64bitmask permissions;
};
enum discord_audit_log_events {
    DISCORD_AUDIT_LOG_GUILD_UPDATE = 1,
    DISCORD_AUDIT_LOG_CHANNEL_CREATE = 10,
    DISCORD_AUDIT_LOG_CHANNEL_UPDATE = 11,
    DISCORD_AUDIT_LOG_CHANNEL_DELETE = 12,
    DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_CREATE = 13,
    DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_UPDATE = 14,
    DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_DELETE = 15,
    DISCORD_AUDIT_LOG_MEMBER_KICK = 20,
    DISCORD_AUDIT_LOG_MEMBER_PRUNE = 21,
    DISCORD_AUDIT_LOG_MEMBER_BAN_ADD = 22,
    DISCORD_AUDIT_LOG_MEMBER_BAN_REMOVE = 23,
    DISCORD_AUDIT_LOG_MEMBER_UPDATE = 24,
    DISCORD_AUDIT_LOG_MEMBER_ROLE_UPDATE = 25,
    DISCORD_AUDIT_LOG_MEMBER_MOVE = 26,
    DISCORD_AUDIT_LOG_MEMBER_DISCONNECT = 27,
    DISCORD_AUDIT_LOG_BOT_ADD = 28,
    DISCORD_AUDIT_LOG_ROLE_CREATE = 30,
    DISCORD_AUDIT_LOG_ROLE_UPDATE = 31,
    DISCORD_AUDIT_LOG_ROLE_DELETE = 32,
    DISCORD_AUDIT_LOG_INVITE_CREATE = 40,
    DISCORD_AUDIT_LOG_INVITE_UPDATE = 41,
    DISCORD_AUDIT_LOG_INVITE_DELETE = 42,
    DISCORD_AUDIT_LOG_WEBHOOK_CREATE = 50,
    DISCORD_AUDIT_LOG_WEBHOOK_UPDATE = 51,
    DISCORD_AUDIT_LOG_WEBHOOK_DELETE = 52,
    DISCORD_AUDIT_LOG_EMOJI_CREATE = 60,
    DISCORD_AUDIT_LOG_EMOJI_UPDATE = 61,
    DISCORD_AUDIT_LOG_EMOJI_DELETE = 62,
    DISCORD_AUDIT_LOG_MESSAGE_DELETE = 72,
    DISCORD_AUDIT_LOG_MESSAGE_BULK_DELETE = 73,
    DISCORD_AUDIT_LOG_MESSAGE_PIN = 74,
    DISCORD_AUDIT_LOG_MESSAGE_UNPIN = 75,
    DISCORD_AUDIT_LOG_INTEGRATION_CREATE = 80,
    DISCORD_AUDIT_LOG_INTEGRATION_UPDATE = 81,
    DISCORD_AUDIT_LOG_INTEGRATION_DELETE = 82,
    DISCORD_AUDIT_LOG_STAGE_INSTANCE_CREATE = 83,
    DISCORD_AUDIT_LOG_STAGE_INSTANCE_UPDATE = 84,
    DISCORD_AUDIT_LOG_STAGE_INSTANCE_DELETE = 85,
    DISCORD_AUDIT_LOG_STICKER_CREATE = 90,
    DISCORD_AUDIT_LOG_STICKER_UPDATE = 91,
    DISCORD_AUDIT_LOG_STICKER_DELETE = 92,
    DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_CREATE = 100,
    DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_UPDATE = 101,
    DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_DELETE = 102,
    DISCORD_AUDIT_LOG_THREAD_CREATE = 110,
    DISCORD_AUDIT_LOG_THREAD_UPDATE = 111,
    DISCORD_AUDIT_LOG_THREAD_DELETE = 112,
    DISCORD_AUDIT_LOG_APPLICATION_COMMAND_PERMISSION_UPDATE = 121,
    DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_CREATE = 140,
    DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_UPDATE = 141,
    DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_DELETE = 142,
    DISCORD_AUDIT_LOG_AUTO_MODERATION_BLOCK_MESSAGE = 143
};
struct discord_audit_log {
 
    struct discord_audit_log_entries * audit_log_entries;
 
 
    struct discord_guild_scheduled_events * guild_scheduled_events;
 
 
    struct discord_integrations * integrations;
 
 
    struct discord_channels * threads;
 
 
    struct discord_users * users;
 
 
    struct discord_webhooks * webhooks;
 
};
struct discord_audit_log_entry {
    u64snowflake target_id;
 
    struct discord_audit_log_changes * changes;
 
    u64snowflake user_id;
    u64snowflake id;
 
    enum discord_audit_log_events action_type;
 
 
    struct discord_optional_audit_entry_infos * options;
 
    char * reason;
};
struct discord_audit_log_entries { int size;
    struct discord_audit_log_entry *array;
int realsize; };
struct discord_optional_audit_entry_info {
    u64snowflake channel_id;
    char * count;
    char * delete_member_days;
    u64snowflake id;
    char * members_removed;
    u64snowflake message_id;
    char * role_name;
    char * type;
};
struct discord_optional_audit_entry_infos { int size;
    struct discord_optional_audit_entry_info *array;
int realsize; };
struct discord_audit_log_change {
    json_char * new_value;
    json_char * old_value;
    char * key;
};
struct discord_audit_log_changes { int size;
    struct discord_audit_log_change *array;
int realsize; };
struct discord_get_guild_audit_log {
    u64snowflake user_id;
    int action_type;
    u64snowflake before;
 
    int limit;
 
};
enum discord_auto_moderation_trigger_types {
    DISCORD_AUTO_MODERATION_KEYWORD = 1,
    DISCORD_AUTO_MODERATION_HARMFUL_LINK = 2,
    DISCORD_AUTO_MODERATION_SPAM = 3,
    DISCORD_AUTO_MODERATION_KEYWORD_PRESET = 4
};
enum discord_auto_moderation_keyword_preset_types {
    DISCORD_AUTO_MODERATION_PROFANITY = 1,
    DISCORD_AUTO_MODERATION_SEXUAL_CONTENT = 2,
    DISCORD_AUTO_MODERATION_SLURS = 3
};
enum discord_auto_moderation_event_types {
    DISCORD_AUTO_MODERATION_MESSAGE_SEND = 1
};
enum discord_auto_moderation_action_types {
    DISCORD_AUTO_MODERATION_ACTION_BLOCK_MESSAGE = 1,
    DISCORD_AUTO_MODERATION_ACTION_SEND_ALERT_MESSAGE = 2,
    DISCORD_AUTO_MODERATION_ACTION_TIMEOUT = 3
};
struct discord_auto_moderation_trigger_metadata {
    struct strings * keyword_filter;
    struct integers * presets;
};
struct discord_auto_moderation_action {
 
    enum discord_auto_moderation_action_types type;
 
 
    struct discord_auto_moderation_action_metadata * metadata;
 
};
struct discord_auto_moderation_actions { int size;
    struct discord_auto_moderation_action *array;
int realsize; };
struct discord_auto_moderation_action_metadata {
 
    u64snowflake channel_id;
 
 
    int duration_seconds;
 
};
struct discord_auto_moderation_rule {
    u64snowflake id;
    u64snowflake guild_id;
    char * name;
    u64snowflake creator_id;
 
    enum discord_auto_moderation_event_types event_type;
 
 
    enum discord_auto_moderation_trigger_types trigger_type;
 
    struct discord_auto_moderation_actions * actions;
    struct discord_auto_moderation_trigger_metadata * trigger_metadata;
    bool enabled;
    struct snowflakes * exempt_roles;
    struct snowflakes * exempt_channels;
};
struct discord_auto_moderation_rules { int size;
    struct discord_auto_moderation_rule *array;
int realsize; };
struct discord_create_auto_moderation_rule {
    char * reason;
    char * name;
 
    enum discord_auto_moderation_event_types event_type;
 
 
    enum discord_auto_moderation_trigger_types trigger_type;
 
 
    struct discord_auto_moderation_actions * actions;
 
 
    struct discord_auto_moderation_trigger_metadata * trigger_metadata;
 
    bool enabled;
 
    struct snowflakes * exempt_roles;
 
 
    struct snowflakes * exempt_channels;
 
};
struct discord_modify_auto_moderation_rule {
    char * reason;
 
    char * name;
 
 
    enum discord_auto_moderation_event_types event_type;
 
 
    struct discord_auto_moderation_trigger_metadata * trigger_metadata;
 
 
    struct discord_auto_moderation_actions * actions;
 
    bool enabled;
 
    struct snowflakes * exempt_roles;
 
 
    struct snowflakes * exempt_channels;
 
};
struct discord_delete_auto_moderation_rule {
    char * reason;
};
enum discord_invite_target_types {
    DISCORD_INVITE_TARGET_STREAM = 1,
    DISCORD_INVITE_TARGET_EMBEDDED_APPLICATION = 2
};
struct discord_invite {
    char * code;
 
    struct discord_guild * guild;
 
    struct discord_channel * channel;
 
    struct discord_user * inviter;
 
 
    enum discord_invite_target_types target_type;
 
 
    struct discord_user * target_user;
 
 
    struct discord_application * target_application;
 
    int approximate_presence_count;
    int approximate_member_count;
 
    u64unix_ms expires_at;
 
 
    struct discord_invite_stage_instance * stage_instance;
 
 
    struct discord_guild_scheduled_event * guild_scheduled_event;
 
};
struct discord_invites { int size;
    struct discord_invite *array;
int realsize; };
struct discord_invite_metadata {
    int uses;
    int max_uses;
    int max_age;
    bool temporary;
 
    u64unix_ms created_at;
 
};
struct discord_invite_stage_instance {
 
    struct discord_guild_members * members;
 
    int participant_count;
    int speaker_count;
    char * topic;
};
struct discord_get_invite {
    bool with_counts;
    bool with_expiration;
 
    u64snowflake guild_scheduled_event_id;
 
};
struct discord_delete_invite {
    char * reason;
};
#define DISCORD_MESSAGE_CROSSPOSTED 1 << 0
#define DISCORD_MESSAGE_IS_CROSSPOST 1 << 1
#define DISCORD_MESSAGE_SUPRPRESS_EMBEDS 1 << 2
#define DISCORD_MESSAGE_SOURCE_MESSAGE_DELETED 1 << 3
#define DISCORD_MESSAGE_URGENT 1 << 4
#define DISCORD_MESSAGE_HAS_THREAD 1 << 5
#define DISCORD_MESSAGE_EPHEMERAL 1 << 6
#define DISCORD_MESSAGE_LOADING 1 << 7
#define DISCORD_MESSAGE_FAILED_TO_MENTION_SOME_ROLES_IN_THREAD 1 << 8
enum discord_channel_types {
    DISCORD_CHANNEL_GUILD_TEXT = 0,
    DISCORD_CHANNEL_DM = 1,
    DISCORD_CHANNEL_GUILD_VOICE = 2,
    DISCORD_CHANNEL_GROUP_DM = 3,
    DISCORD_CHANNEL_GUILD_CATEGORY = 4,
    DISCORD_CHANNEL_GUILD_NEWS = 5,
    DISCORD_CHANNEL_GUILD_STORE = 6,
    DISCORD_CHANNEL_GUILD_NEWS_THREAD = 10,
    DISCORD_CHANNEL_GUILD_PUBLIC_THREAD = 11,
    DISCORD_CHANNEL_GUILD_PRIVATE_THREAD = 12,
    DISCORD_CHANNEL_GUILD_STAGE_VOICE = 13,
    DISCORD_CHANNEL_GUILD_DIRECTORY = 14,
    DISCORD_CHANNEL_GUILD_FORUM = 15
};
enum discord_video_quality_modes {
    DISCORD_VIDEO_QUALITY_AUTO = 1,
    DISCORD_VIDEO_QUALITY_FULL = 2
};
enum discord_message_types {
    DISCORD_MESSAGE_DEFAULT = 0,
    DISCORD_MESSAGE_RECIPIENT_ADD = 1,
    DISCORD_MESSAGE_RECIPIENT_REMOVE = 2,
    DISCORD_MESSAGE_CALL = 3,
    DISCORD_MESSAGE_CHANNEL_NAME_CHANGE = 4,
    DISCORD_MESSAGE_CHANNEL_ICON_CHANGE = 5,
    DISCORD_MESSAGE_CHANNEL_PINNED_MESSAGE = 6,
    DISCORD_MESSAGE_GUILD_MEMBER_JOIN = 7,
    DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION = 8,
    DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9,
    DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10,
    DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11,
    DISCORD_MESSAGE_CHANNEL_FOLLOW_ADD = 12,
    DISCORD_MESSAGE_GUILD_DISCOVERY_DISQUALIFIED = 14,
    DISCORD_MESSAGE_GUILD_DISCOVERY_REQUALIFIED = 15,
    DISCORD_MESSAGE_GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = 16,
    DISCORD_MESSAGE_GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = 17,
    DISCORD_MESSAGE_THREAD_CREATED = 18,
    DISCORD_MESSAGE_REPLY = 19,
    DISCORD_MESSAGE_CHAT_INPUT_COMMAND = 20,
    DISCORD_MESSAGE_THREAD_STARTER_MESSAGE = 21,
    DISCORD_MESSAGE_GUILD_INVITE_REMINDER = 22,
    DISCORD_MESSAGE_CONTEXT_MENU_COMMAND = 22
};
enum discord_message_activity_types {
    DISCORD_MESSAGE_ACTIVITY_JOIN = 1,
    DISCORD_MESSAGE_ACTIVITY_SPECTATE = 2,
    DISCORD_MESSAGE_ACTIVITY_LISTEN = 3,
    DISCORD_MESSAGE_ACTIVITY_JOIN_REQUEST = 5
};
struct discord_channel {
    u64snowflake id;
    enum discord_channel_types type;
 
    u64snowflake guild_id;
 
    int position;
    struct discord_overwrites * permission_overwrites;
    char * name;
    char * topic;
    bool nsfw;
    u64snowflake last_message_id;
    int bitrate;
    int user_limit;
    int rate_limit_per_user;
    struct discord_users * recipients;
    char * icon;
    u64snowflake owner_id;
    u64snowflake application_id;
    u64snowflake parent_id;
    u64unix_ms last_pin_timestamp;
    char * rtc_region;
    int voice_quality_mode;
    int message_count;
    int member_count;
    struct discord_thread_metadata * thread_metadata;
    struct discord_thread_member * member;
    int default_auto_archive_duration;
    u64bitmask permissions;
};
struct discord_channels { int size;
    struct discord_channel *array;
int realsize; };
struct discord_message {
    u64snowflake id;
    u64snowflake channel_id;
    u64snowflake guild_id;
    struct discord_user * author;
    struct discord_guild_member * member;
    char * content;
    u64unix_ms timestamp;
 
    u64unix_ms edited_timestamp;
 
    bool tts;
    bool mention_everyone;
    struct discord_users * mentions;
    struct discord_roles * mention_roles;
    struct discord_channels * mention_channels;
    struct discord_attachments * attachments;
    struct discord_embeds * embeds;
    struct discord_reactions * reactions;
    json_char * nonce;
    bool pinned;
    u64snowflake webhook_id;
    enum discord_message_types type;
    struct discord_message_activity * activity;
    struct discord_application * application;
    u64snowflake application_id;
    struct discord_message_reference * message_reference;
    u64bitmask flags;
    struct discord_message * referenced_message;
    struct discord_message_interaction * interaction;
    struct discord_channel * thread;
    struct discord_components * components;
    struct discord_sticker_items * sticker_items;
};
struct discord_messages { int size;
    struct discord_message *array;
int realsize; };
struct discord_message_activity {
    enum discord_message_activity_types type;
    char * party_id;
};
struct discord_message_reference {
    u64snowflake message_id;
    u64snowflake channel_id;
    u64snowflake guild_id;
    bool fail_if_not_exists;
};
struct discord_followed_channel {
    u64snowflake channel_id;
    u64snowflake webhook_id;
};
struct discord_reaction {
    int count;
    bool me;
    struct discord_emoji * emoji;
};
struct discord_reactions { int size;
    struct discord_reaction *array;
int realsize; };
struct discord_overwrite {
    u64snowflake id;
    int type;
    u64bitmask allow;
    u64bitmask deny;
};
struct discord_overwrites { int size;
    struct discord_overwrite *array;
int realsize; };
struct discord_thread_metadata {
    bool archived;
    int auto_archive_duration;
    u64unix_ms archive_timestamp;
    bool locked;
    bool invitable;
    u64unix_ms create_timestamp;
};
struct discord_thread_member {
    u64snowflake id;
    u64snowflake user_id;
    u64unix_ms join_timestamp;
    u64bitmask flags;
    u64snowflake guild_id;
};
struct discord_thread_members { int size;
    struct discord_thread_member *array;
int realsize; };
struct discord_attachment {
    char * content;
    u64snowflake id;
 
    char * filename;
 
 
    char * description;
 
 
    char * content_type;
 
 
    size_t size;
 
 
    char * url;
 
 
    char * proxy_url;
 
 
    int height;
 
 
    int width;
 
    bool ephemeral;
};
struct discord_attachments { int size;
    struct discord_attachment *array;
int realsize; };
struct discord_embed {
    char * title;
    char * type;
    char * description;
    char * url;
 
    u64unix_ms timestamp;
 
 
    int color;
 
 
    struct discord_embed_footer * footer;
 
 
    struct discord_embed_image * image;
 
 
    struct discord_embed_thumbnail * thumbnail;
 
 
    struct discord_embed_video * video;
 
 
    struct discord_embed_provider * provider;
 
 
    struct discord_embed_author * author;
 
 
    struct discord_embed_fields * fields;
 
};
struct discord_embeds { int size;
    struct discord_embed *array;
int realsize; };
struct discord_embed_thumbnail {
    char * url;
 
    char * proxy_url;
 
 
    int height;
 
 
    int width;
 
};
struct discord_embed_video {
 
    char * url;
 
 
    char * proxy_url;
 
 
    int height;
 
 
    int width;
 
};
struct discord_embed_image {
    char * url;
 
    char * proxy_url;
 
 
    int height;
 
 
    int width;
 
};
struct discord_embed_provider {
 
    char * name;
 
 
    char * url;
 
};
struct discord_embed_author {
    char * name;
 
    char * url;
 
 
    char * icon_url;
 
 
    char * proxy_icon_url;
 
};
struct discord_embed_footer {
    char * text;
 
    char * icon_url;
 
 
    char * proxy_icon_url;
 
};
struct discord_embed_field {
    char * name;
    char * value;
    bool Inline;
};
struct discord_embed_fields { int size;
    struct discord_embed_field *array;
int realsize; };
struct discord_channel_mention {
    u64snowflake id;
    u64snowflake guild_id;
    enum discord_channel_types type;
    char * name;
};
struct discord_allowed_mention {
    struct strings * parse;
    struct snowflakes * roles;
    struct snowflakes * users;
    bool replied_user;
};
struct discord_thread_response_body {
    struct discord_channels * threads;
    struct discord_thread_members * members;
    bool has_more;
};
struct discord_modify_channel {
    char * reason;
    char * name;
    enum discord_channel_types type;
 
    int position;
 
    char * topic;
    bool nsfw;
 
    int rate_limit_per_user;
 
 
    int user_limit;
 
 
    struct discord_overwrites * permission_overwrites;
 
 
    u64snowflake parent_id;
 
    char * rtc_region;
 
    int video_quality_mode;
 
 
    int default_auto_archive_duration;
 
    bool archived;
 
    int auto_archive_duration;
 
    bool locked;
    bool invitable;
};
struct discord_delete_channel {
    char * reason;
};
struct discord_get_channel_messages {
 
    u64snowflake around;
 
 
    u64snowflake before;
 
 
    u64snowflake after;
 
 
    int limit;
 
};
struct discord_create_message {
    char * content;
    bool tts;
    struct discord_embeds * embeds;
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_message_reference * message_reference;
 
 
    struct discord_components * components;
 
 
    struct snowflakes * sticker_ids;
 
 
    struct discord_attachments * attachments;
 
 
    u64bitmask flags;
 
};
struct discord_get_reactions {
 
    u64snowflake after;
 
 
    int limit;
 
};
struct discord_edit_message {
    char * content;
    struct discord_embeds * embeds;
 
    u64bitmask flags;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
};
struct discord_delete_message {
    char * reason;
};
struct discord_bulk_delete_messages {
    char * reason;
    struct snowflakes * messages;
};
struct discord_edit_channel_permissions {
    char * reason;
 
    u64bitmask allow;
 
 
    u64bitmask deny;
 
    int type;
};
struct discord_create_channel_invite {
    char * reason;
 
    int max_age;
 
 
    int max_uses;
 
 
    bool temporary;
 
 
    bool unique;
 
 
    enum discord_invite_target_types target_type;
 
 
    u64snowflake target_user_id;
 
 
    u64snowflake target_application_id;
 
};
struct discord_delete_channel_permission {
    char * reason;
};
struct discord_follow_news_channel {
 
    u64snowflake webhook_channel_id;
 
};
struct discord_pin_message {
    char * reason;
};
struct discord_unpin_message {
    char * reason;
};
struct discord_group_dm_add_recipient {
    char * access_token;
    char * nick;
};
struct discord_start_thread_with_message {
    char * reason;
    char * name;
 
    int auto_archive_duration;
 
 
    int rate_limit_per_user;
 
};
struct discord_start_thread_without_message {
    char * reason;
    char * name;
 
    int auto_archive_duration;
 
    enum discord_channel_types type;
    bool invitable;
 
    int rate_limit_per_user;
 
};
struct discord_list_active_threads {
 
    struct discord_channels * threads;
 
 
    struct discord_thread_members * members;
 
    bool has_more;
};
struct discord_emoji {
    u64snowflake id;
    char * name;
 
    struct discord_roles * roles;
 
 
    struct discord_user * user;
 
    bool require_colons;
    bool managed;
    bool animated;
    bool available;
};
struct discord_emojis { int size;
    struct discord_emoji *array;
int realsize; };
struct discord_create_guild_emoji {
    char * reason;
    char * name;
    char * image;
 
    struct snowflakes * roles;
 
};
struct discord_modify_guild_emoji {
    char * reason;
    char * name;
    char * image;
 
    struct snowflakes * roles;
 
};
struct discord_delete_guild_emoji {
    char * reason;
};
#define DISCORD_SYSTEM_SUPPRESS_JOIN_NOTIFICATIONS 1 << 0
#define DISCORD_SYSTEM_SUPPRESS_PREMIUM_NOTIFICATIONS 1 << 1
#define DISCORD_SYSTEM_SUPPRESS_GUILD_REMINDER_NOTIFICATIONS 1 << 2
#define DISCORD_SYSTEM_SUPPRESS_JOIN_NOTIFICATION_REPLIES 1 << 3
enum discord_message_notification_level {
    DISCORD_MESSAGE_NOTIFICATION_ALL_MESSAGES = 0,
    DISCORD_MESSAGE_NOTIFICATION_ONLY_MESSAGES = 1
};
enum discord_explicit_content_filter_level {
    DISCORD_EXPLICIT_CONTENT_DISABLED = 0,
    DISCORD_EXPLICIT_CONTENT_MEMBERS_WITHOUT_ROLES = 1,
    DISCORD_MESSAGE_NOTIFICATION_ALL_MEMBERS = 2
};
enum discord_mfa_level {
    DISCORD_MFA_NONE = 0,
    DISCORD_MFA_ELEVATED = 1
};
enum discord_verification_level {
    DISCORD_VERIFICATION_NONE = 0,
    DISCORD_VERIFICATION_LOW = 1,
    DISCORD_VERIFICATION_MEDIUM = 2,
    DISCORD_VERIFICATION_HIGH = 3,
    DISCORD_VERIFICATION_VERY_HIGH = 4
};
enum discord_guild_nsfw_level {
    DISCORD_GUILD_NSFW_DEFAULT = 0,
    DISCORD_GUILD_NSFW_EXPLICIT = 1,
    DISCORD_GUILD_NSFW_SAFE = 2,
    DISCORD_GUILD_NSFW_AGE_RESTRICTED = 3
};
enum discord_premium_tier {
    DISCORD_PREMIUM_TIER_NONE = 0,
    DISCORD_PREMIUM_TIER_1 = 1,
    DISCORD_PREMIUM_TIER_2 = 2,
    DISCORD_PREMIUM_TIER_3 = 3
};
enum discord_integration_expire_behaviors {
    DISCORD_INTEGRATION_REMOVE_ROLE = 0,
    DISCORD_INTEGRATION_KICK = 1
};
struct discord_guild {
    u64snowflake id;
    char * name;
    char * icon;
 
    char * icon_hash;
 
    char * splash;
    char * discovery_splash;
    bool owner;
    u64snowflake owner_id;
 
    u64bitmask permissions;
 
    u64snowflake afk_channel_id;
    int afk_timeout;
    bool widget_enabled;
    u64snowflake widget_channel_id;
    enum discord_verification_level verification_level;
    enum discord_message_notification_level default_message_notifications;
    enum discord_explicit_content_filter_level explicit_content_filter;
    struct discord_roles * roles;
    struct discord_emojis * emojis;
    struct strings * features;
    enum discord_mfa_level mfa_level;
    u64snowflake application_id;
    u64snowflake system_channel_id;
    u64bitmask system_channel_flags;
    u64snowflake rules_channel_id;
 
    u64unix_ms joined_at;
 
    bool large;
    bool unavailable;
    int member_count;
 
    struct discord_voice_states * voice_states;
 
 
    struct discord_guild_members * members;
 
 
    struct discord_channels * channels;
 
 
    struct discord_channels * threads;
 
 
    struct discord_presence_updates * presences;
 
 
    int max_presences;
 
 
    int max_members;
 
    char * vanity_url_code;
    char * description;
    char * banner;
    enum discord_premium_tier premium_tier;
    int premium_subscription_count;
    char * preferred_locale;
    u64snowflake public_updates_channel_id;
 
    int max_video_channel_users;
 
 
    int approximate_member_count;
 
 
    int approximate_presence_count;
 
 
    struct discord_welcome_screen * welcome_screen;
 
    enum discord_guild_nsfw_level nsfw_level;
 
    struct discord_stage_instances * stage_instances;
 
 
    struct discord_stickers * stickers;
 
 
    struct discord_guild_scheduled_events * guild_scheduled_events;
 
    bool premium_progress_bar_enabled;
};
struct discord_guilds { int size;
    struct discord_guild *array;
int realsize; };
struct discord_guild_preview {
    u64snowflake id;
    char * name;
    char * icon;
    char * splash;
    char * discovery_splash;
    struct discord_emojis * emojis;
    struct strings * features;
    int approximate_member_count;
    int approximate_presence_count;
    char * description;
    struct discord_stickers * stickers;
};
struct discord_guild_widget_settings {
    char * reason;
    bool enabled;
    u64snowflake channel_id;
};
struct discord_guild_widget {
    u64snowflake id;
    char * name;
    char * instant_invite;
    struct discord_channels * channels;
    struct discord_users * members;
    int presence_count;
};
struct discord_guild_member {
 
    struct discord_user * user;
 
 
    char * nick;
 
 
    char * avatar;
 
    struct snowflakes * roles;
    u64unix_ms joined_at;
 
    u64unix_ms premium_since;
 
    bool deaf;
    bool muted;
    bool pending;
 
    u64bitmask permissions;
 
    u64unix_ms communication_disabled_until;
    u64snowflake guild_id;
};
struct discord_guild_members { int size;
    struct discord_guild_member *array;
int realsize; };
struct discord_integration {
    u64snowflake id;
    char * name;
    char * type;
    bool enabled;
    bool syncing;
    u64snowflake role_id;
    bool enable_emoticons;
    enum discord_integration_expire_behaviors expire_behavior;
    int expire_grace_period;
    struct discord_user * user;
    struct discord_integration_account * account;
    u64unix_ms synced_at;
    int subscriber_count;
    bool revoked;
    struct discord_integration_application * application;
    u64snowflake guild_id;
};
struct discord_integrations { int size;
    struct discord_integration *array;
int realsize; };
struct discord_integration_account {
    char * id;
    char * name;
};
struct discord_integration_application {
    u64snowflake id;
    char * name;
    char * icon;
    char * description;
    char * summary;
 
    struct discord_user * bot;
 
};
struct discord_ban {
    char * reason;
    struct discord_user * user;
};
struct discord_bans { int size;
    struct discord_ban *array;
int realsize; };
struct discord_welcome_screen {
    char * description;
 
    struct discord_welcome_screen_channels * welcome_channels;
 
};
struct discord_welcome_screen_channel {
    u64snowflake channel_id;
    char * description;
    u64snowflake emoji_id;
    char * emoji_name;
};
struct discord_welcome_screen_channels { int size;
    struct discord_welcome_screen_channel *array;
int realsize; };
struct discord_prune_count {
    int pruned;
};
struct discord_create_guild {
    char * reason;
    char * name;
 
    char * region;
 
 
    char * icon;
 
    enum discord_verification_level verification_level;
    enum discord_message_notification_level default_message_notifications;
    enum discord_explicit_content_filter_level explicit_content_filter;
 
    struct discord_roles * roles;
 
 
    struct discord_channels * channels;
 
 
    u64snowflake afk_channel_id;
 
    int afk_timeout;
    u64snowflake system_channel_id;
    u64bitmask system_channel_flags;
};
struct discord_modify_guild {
    char * reason;
    char * name;
    enum discord_verification_level verification_level;
    enum discord_message_notification_level default_message_notifications;
    enum discord_explicit_content_filter_level explicit_content_filter;
    u64snowflake afk_channel_id;
    int afk_timeout;
    char * icon;
    u64snowflake owner_id;
    char * splash;
    char * discovery_splash;
    char * banner;
    u64snowflake system_channel_id;
    u64bitmask system_channel_flags;
    u64snowflake rules_channel_id;
    u64snowflake public_updates_channel_id;
    char * preferred_locale;
    struct strings * features;
    char * description;
    bool premium_progress_bar_enabled;
};
struct discord_create_guild_channel {
    char * reason;
    char * name;
    enum discord_channel_types type;
    char * topic;
 
    int bitrate;
 
 
    int user_limit;
 
    int rate_limit_per_user;
    int position;
    struct discord_overwrites * permission_overwrites;
 
    u64snowflake parent_id;
 
    bool nsfw;
};
struct discord_modify_guild_channel_position {
    u64snowflake id;
 
    int position;
 
    bool lock_category;
 
    u64snowflake parent_id;
 
};
struct discord_modify_guild_channel_positions { int size;
    struct discord_modify_guild_channel_position *array;
int realsize; };
struct discord_list_active_guild_threads {
    struct discord_channels * threads;
    struct discord_thread_members * members;
};
struct discord_list_guild_members {
    int limit;
    u64snowflake after;
};
struct discord_search_guild_members {
    char * query;
    int limit;
};
struct discord_add_guild_member {
    char * access_token;
    char * nick;
    struct snowflakes * roles;
    bool mute;
    bool deaf;
};
struct discord_modify_guild_member {
    char * reason;
 
    char * nick;
 
 
    struct snowflakes * roles;
 
 
    bool mute;
 
 
    bool deaf;
 
 
    u64snowflake channel_id;
 
 
    u64unix_ms communication_disabled_until;
 
};
struct discord_modify_current_member {
    char * reason;
 
    char * nick;
 
};
struct discord_modify_current_user_nick {
    char * reason;
 
    char * nick;
 
};
struct discord_add_guild_member_role {
    char * reason;
};
struct discord_remove_guild_member_role {
    char * reason;
};
struct discord_remove_guild_member {
    char * reason;
};
struct discord_create_guild_ban {
    char * reason;
 
    int delete_message_days;
 
};
struct discord_remove_guild_ban {
    char * reason;
};
struct discord_create_guild_role {
    char * reason;
    char * name;
    u64bitmask permissions;
    int color;
    bool hoist;
    char * icon;
    char * unicode_emoji;
    bool mentionable;
};
struct discord_modify_guild_role_position {
    u64snowflake id;
 
    int position;
 
};
struct discord_modify_guild_role_positions { int size;
    struct discord_modify_guild_role_position *array;
int realsize; };
struct discord_modify_guild_role {
    char * reason;
    char * name;
    u64bitmask permissions;
    int color;
    bool hoist;
    char * icon;
    char * unicode_emoji;
    bool mentionable;
};
struct discord_delete_guild_role {
    char * reason;
};
struct discord_get_guild_prune_count {
 
    int days;
 
    struct snowflakes * include_roles;
};
struct discord_begin_guild_prune {
    char * reason;
 
    int days;
 
    bool compute_prune_count;
    struct snowflakes * include_roles;
};
struct discord_delete_guild_integrations {
    char * reason;
 
    int days;
 
    struct snowflakes * include_roles;
};
struct discord_get_guild_widget_image {
 
    char * style;
 
};
struct discord_modify_guild_welcome_screen {
    char * reason;
    bool enabled;
    struct discord_welcome_screen_channels * welcome_channels;
 
    char * description;
 
};
struct discord_modify_current_user_voice_state {
    u64snowflake channel_id;
    bool suppress;
 
    u64unix_ms request_to_speak_timestamp;
 
};
struct discord_modify_user_voice_state {
    u64snowflake channel_id;
    bool suppress;
};
enum discord_guild_scheduled_event_privacy_level {
    DISCORD_GUILD_SCHEDULED_EVENT_GUILD_ONLY = 2
};
enum discord_guild_scheduled_event_entity_types {
    DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_STAGE_INSTANCE = 1,
    DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_VOICE = 2,
    DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_EXTERNAL = 3
};
enum discord_guild_scheduled_event_status {
    DISCORD_GUILD_SCHEDULED_EVENT_SCHEDULED = 1,
    DISCORD_GUILD_SCHEDULED_EVENT_ACTIVE = 2,
    DISCORD_GUILD_SCHEDULED_EVENT_COMPLETED = 3,
    DISCORD_GUILD_SCHEDULED_EVENT_CANCELED = 4
};
struct discord_guild_scheduled_event {
    u64snowflake id;
    u64snowflake guild_id;
    u64snowflake channel_id;
    u64snowflake creator_id;
    char * name;
    char * description;
    u64unix_ms scheduled_start_time;
    u64unix_ms scheduled_end_time;
 
    enum discord_guild_scheduled_event_privacy_level privacy_level;
 
 
    enum discord_guild_scheduled_event_status status;
 
 
    enum discord_guild_scheduled_event_entity_types entity_type;
 
    u64snowflake entity_id;
 
    struct discord_guild_scheduled_event_entity_metadata * entity_metadata;
 
 
    struct discord_user * creator;
 
    int user_count;
    char * image;
};
struct discord_guild_scheduled_event_entity_metadata {
 
    char * location;
 
};
struct discord_guild_scheduled_events { int size;
    struct discord_guild_scheduled_event *array;
int realsize; };
struct discord_guild_scheduled_event_user {
    u64snowflake guild_scheduled_event_id;
 
    struct discord_user * user;
 
 
    struct discord_guild_member * member;
 
};
struct discord_guild_scheduled_event_users { int size;
    struct discord_guild_scheduled_event_user *array;
int realsize; };
struct discord_list_guild_scheduled_events {
    bool with_user_count;
};
struct discord_create_guild_scheduled_event {
    char * reason;
 
    u64snowflake channel_id;
 
 
    struct discord_guild_scheduled_event_entity_metadata * entity_metadata;
 
    char * name;
 
    enum discord_guild_scheduled_event_privacy_level privacy_level;
 
 
    u64unix_ms scheduled_start_time;
 
 
    u64unix_ms scheduled_end_time;
 
 
    char * description;
 
 
    enum discord_guild_scheduled_event_entity_types entity_type;
 
 
    char * image;
 
};
struct discord_get_guild_scheduled_event {
    bool with_user_count;
};
struct discord_modify_guild_scheduled_event {
    char * reason;
 
    u64snowflake channel_id;
 
 
    struct discord_guild_scheduled_event_entity_metadata * entity_metadata;
 
    char * name;
 
    u64unix_ms scheduled_start_time;
 
 
    u64unix_ms scheduled_end_time;
 
 
    char * description;
 
 
    enum discord_guild_scheduled_event_entity_types entity_type;
 
 
    enum discord_guild_scheduled_event_status status;
 
 
    char * image;
 
};
struct discord_get_guild_scheduled_event_users {
    int limit;
    bool with_member;
 
    u64snowflake before;
 
 
    u64snowflake after;
 
};
struct discord_guild_template {
    char * code;
    char * name;
    char * description;
    int usage_count;
    u64snowflake creator_id;
    struct discord_user * creator;
    u64unix_ms created_at;
    u64unix_ms updated_at;
    u64snowflake source_guild_id;
    struct discord_guild * serialized_source_guild;
    bool is_dirty;
};
struct discord_guild_templates { int size;
    struct discord_guild_template *array;
int realsize; };
struct discord_create_guild_from_guild_template {
    char * name;
 
    char * icon;
 
};
struct discord_create_guild_template {
    char * name;
 
    char * description;
 
};
struct discord_modify_guild_template {
 
    char * name;
 
 
    char * description;
 
};
enum discord_privacy_level {
    DISCORD_PRIVACY_PUBLIC = 1,
    DISCORD_PRIVACY_GUILD_ONLY = 2
};
struct discord_stage_instance {
    u64snowflake id;
    u64snowflake guild_id;
    u64snowflake channel_id;
    char * topic;
 
    enum discord_privacy_level privacy_level;
 
    bool discoverable_disabled;
};
struct discord_stage_instances { int size;
    struct discord_stage_instance *array;
int realsize; };
struct discord_create_stage_instance {
    char * reason;
    u64snowflake channel_id;
    char * topic;
 
    enum discord_privacy_level privacy_level;
 
};
struct discord_modify_stage_instance {
    char * reason;
    char * topic;
 
    enum discord_privacy_level privacy_level;
 
};
struct discord_delete_stage_instance {
    char * reason;
};
enum discord_sticker_types {
    DISCORD_STICKER_STANDARD = 1,
    DISCORD_STICKER_GUILD = 2
};
enum discord_sticker_format_types {
    DISCORD_STICKER_FORMAT_PNG = 1,
    DISCORD_STICKER_FORMAT_APNG = 2,
    DISCORD_STICKER_FORMAT_LOTTIE = 3
};
struct discord_sticker {
    u64snowflake id;
 
    u64snowflake pack_id;
 
    char * name;
    char * description;
    char * tags;
 
    enum discord_sticker_types type;
 
 
    enum discord_sticker_format_types format_type;
 
    bool available;
 
    u64snowflake guild_id;
 
 
    struct discord_user * user;
 
    int sort_value;
};
struct discord_stickers { int size;
    struct discord_sticker *array;
int realsize; };
struct discord_sticker_item {
    u64snowflake id;
    char * name;
 
    enum discord_sticker_format_types format_type;
 
};
struct discord_sticker_items { int size;
    struct discord_sticker_item *array;
int realsize; };
struct discord_sticker_pack {
    u64snowflake id;
 
    struct discord_stickers * stickers;
 
    char * name;
    u64snowflake sku_id;
 
    u64snowflake cover_sticker_id;
 
    char * description;
 
    u64snowflake banner_asset_id;
 
};
struct discord_sticker_packs { int size;
    struct discord_sticker_pack *array;
int realsize; };
struct discord_list_nitro_sticker_packs {
    struct discord_sticker_packs * sticker_packs;
};
struct discord_create_guild_sticker {
    char * reason;
    char * name;
    char * description;
    char * tags;
    struct discord_attachment * file;
};
struct discord_modify_guild_sticker {
    char * name;
    char * description;
    char * tags;
};
struct discord_delete_guild_sticker {
    char * reason;
};
#define DISCORD_USER_NONE 0
#define DISCORD_USER_STAFF 1 << 0
#define DISCORD_USER_PARTNER 1 << 1
#define DISCORD_USER_HYPESQUAD 1 << 2
#define DISCORD_USER_BUG_HUNTER_LEVEL_1 1 << 3
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_1 1 << 6
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_2 1 << 7
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_3 1 << 8
#define DISCORD_USER_PREMIUM_EARLY_SUPPORTER 1 << 9
#define DISCORD_USER_TEAM_PSEUDO_USER 1 << 10
#define DISCORD_USER_BUG_HUNTER_LEVEL_2 1 << 14
#define DISCORD_USER_VERIFIED_BOT 1 << 16
#define DISCORD_USER_VERIFIED_DEVELOPER 1 << 17
#define DISCORD_USER_CERTIFIED_MODERATOR 1 << 18
#define DISCORD_USER_BOT_HTTP_INTERACTIONS 1 << 19
enum discord_premium_types {
    DISCORD_PREMIUM_NONE = 0,
    DISCORD_PREMIUM_NITRO_CLASSIC = 1,
    DISCORD_PREMIUM_NITRO = 2
};
enum discord_visibility_types {
    DISCORD_VISIBILITY_NONE = 0,
    DISCORD_VISIBILITY_EVERYONE = 1
};
struct discord_user {
    u64snowflake id;
    char * username;
    char * discriminator;
    char * avatar;
    bool bot;
    bool System;
    bool mfa_enabled;
    char * banner;
    int accent_color;
    char * locale;
    bool verified;
    char * email;
    u64bitmask flags;
    enum discord_premium_types premium_type;
    u64bitmask public_flags;
};
struct discord_users { int size;
    struct discord_user *array;
int realsize; };
struct discord_connection {
    u64snowflake id;
    char * name;
    char * type;
    bool revoked;
 
    struct discord_integrations * integrations;
 
    bool verified;
    bool friend_sync;
    bool show_activity;
    enum discord_visibility_types visibility;
};
struct discord_connections { int size;
    struct discord_connection *array;
int realsize; };
struct discord_modify_current_user {
 
    char * username;
 
 
    char * avatar;
 
};
struct discord_get_current_user_guilds {
 
    u64snowflake before;
 
 
    u64snowflake after;
 
 
    int limit;
 
};
struct discord_create_dm {
 
    u64snowflake recipient_id;
 
};
struct discord_create_group_dm {
 
    struct snowflakes * access_tokens;
 
 
    struct strings * nicks;
 
};
struct discord_voice_state {
    u64snowflake guild_id;
    u64snowflake channel_id;
    u64snowflake user_id;
    struct discord_guild_member * member;
    char * session_id;
    bool deaf;
    bool mute;
    bool self_deaf;
    bool self_mute;
    bool self_stream;
    bool self_video;
    bool suppress;
 
    u64unix_ms request_to_speak_timestamp;
 
};
struct discord_voice_states { int size;
    struct discord_voice_state *array;
int realsize; };
struct discord_voice_region {
    char * id;
    char * name;
    bool optimal;
    bool deprecated;
    bool custom;
};
struct discord_voice_regions { int size;
    struct discord_voice_region *array;
int realsize; };
enum discord_webhook_types {
    DISCORD_WEBHOOK_INCOMING = 1,
    DISCORD_WEBHOOK_CHANNEL_FOLLOWER = 2,
    DISCORD_WEBHOOK_APPLICATION = 3
};
struct discord_webhook {
    u64snowflake id;
 
    enum discord_webhook_types type;
 
    u64snowflake guild_id;
    u64snowflake channel_id;
 
    struct discord_user * user;
 
    char * name;
    char * token;
    u64snowflake application_id;
 
    struct discord_channel * source_channel;
 
    char * url;
};
struct discord_webhooks { int size;
    struct discord_webhook *array;
int realsize; };
struct discord_create_webhook {
    char * reason;
    char * name;
 
    char * avatar;
 
};
struct discord_modify_webhook {
    char * reason;
    char * name;
 
    char * avatar;
 
    u64snowflake channel_id;
};
struct discord_delete_webhook {
    char * reason;
};
struct discord_modify_webhook_with_token {
    char * name;
 
    char * avatar;
 
};
struct discord_execute_webhook {
    bool wait;
    u64snowflake thread_id;
    char * content;
    char * username;
    char * avatar_url;
    bool tts;
 
    struct discord_embeds * embeds;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
 
    u64bitmask flags;
 
};
struct discord_get_webhook_message {
 
    u64snowflake thread_id;
 
};
struct discord_edit_webhook_message {
    u64snowflake thread_id;
    char * content;
 
    struct discord_embeds * embeds;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
};
struct discord_delete_webhook_message {
 
    u64snowflake thread_id;
 
};
#define DISCORD_GATEWAY_GUILDS 1 << 0
#define DISCORD_GATEWAY_GUILD_MEMBERS 1 << 1
#define DISCORD_GATEWAY_GUILD_BANS 1 << 2
#define DISCORD_GATEWAY_GUILD_EMOJIS_AND_STICKERS 1 << 3
#define DISCORD_GATEWAY_GUILD_INTEGRATIONS 1 << 4
#define DISCORD_GATEWAY_GUILD_WEBHOOKS 1 << 5
#define DISCORD_GATEWAY_GUILD_INVITES 1 << 6
#define DISCORD_GATEWAY_GUILD_VOICE_STATES 1 << 7
#define DISCORD_GATEWAY_GUILD_PRESENCES 1 << 8
#define DISCORD_GATEWAY_GUILD_MESSAGES 1 << 9
#define DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS 1 << 10
#define DISCORD_GATEWAY_GUILD_MESSAGE_TYPING 1 << 11
#define DISCORD_GATEWAY_DIRECT_MESSAGES 1 << 12
#define DISCORD_GATEWAY_DIRECT_MESSAGE_REACTIONS 1 << 13
#define DISCORD_GATEWAY_DIRECT_MESSAGE_TYPING 1 << 14
#define DISCORD_GATEWAY_MESSAGE_CONTENT 1 << 15
#define DISCORD_GATEWAY_GUILD_SCHEDULED_EVENTS 1 << 16
#define DISCORD_GATEWAY_AUTO_MODERATION_CONFIGURATION 1 << 20
#define DISCORD_GATEWAY_AUTO_MODERATION_EXECUTION 1 << 21
#define DISCORD_ACTIVITY_INSTANCE 1 << 0
#define DISCORD_ACTIVITY_JOIN 1 << 1
#define DISCORD_ACTIVITY_SPECTATE 1 << 2
#define DISCORD_ACTIVITY_JOIN_REQUEST 1 << 3
#define DISCORD_ACTIVITY_SYNC 1 << 4
#define DISCORD_ACTIVITY_PLAY 1 << 5
#define DISCORD_ACTIVITY_PARTY_PRIVACY_FRIENDS 1 << 6
#define DISCORD_ACTIVITY_PARTY_PRIVACY_VOICE_CHANNEL 1 << 7
#define DISCORD_ACTIVITY_EMBEDDED 1 << 8
enum discord_gateway_close_opcodes {
    DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_ERROR = 4000,
    DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_OPCODE = 4001,
    DISCORD_GATEWAY_CLOSE_REASON_DECODE_ERROR = 4002,
    DISCORD_GATEWAY_CLOSE_REASON_NOT_AUTHENTICATED = 4003,
    DISCORD_GATEWAY_CLOSE_REASON_AUTHENTICATION_FAILED = 4004,
    DISCORD_GATEWAY_CLOSE_REASON_ALREADY_AUTHENTICATED = 4005,
    DISCORD_GATEWAY_CLOSE_REASON_INVALID_SEQUENCE = 4007,
    DISCORD_GATEWAY_CLOSE_REASON_RATE_LIMITED = 4008,
    DISCORD_GATEWAY_CLOSE_REASON_SESSION_TIMED_OUT = 4009,
    DISCORD_GATEWAY_CLOSE_REASON_INVALID_SHARD = 4010,
    DISCORD_GATEWAY_CLOSE_REASON_SHARDING_REQUIRED = 4011,
    DISCORD_GATEWAY_CLOSE_REASON_INVALID_API_VERSION = 4012,
    DISCORD_GATEWAY_CLOSE_REASON_INVALID_INTENTS = 4013,
    DISCORD_GATEWAY_CLOSE_REASON_DISALLOWED_INTENTS = 4014,
    DISCORD_GATEWAY_CLOSE_REASON_RECONNECT = 4900
};
enum discord_gateway_opcodes {
    DISCORD_GATEWAY_DISPATCH = 0,
    DISCORD_GATEWAY_HEARTBEAT = 1,
    DISCORD_GATEWAY_IDENTIFY = 2,
    DISCORD_GATEWAY_PRESENCE_UPDATE = 3,
    DISCORD_GATEWAY_VOICE_STATE_UPDATE = 4,
    DISCORD_GATEWAY_RESUME = 6,
    DISCORD_GATEWAY_RECONNECT = 7,
    DISCORD_GATEWAY_REQUEST_GUILD_MEMBERS = 8,
    DISCORD_GATEWAY_INVALID_SESSION = 9,
    DISCORD_GATEWAY_HELLO = 10,
    DISCORD_GATEWAY_HEARTBEAT_ACK = 11
};
enum discord_activity_types {
    DISCORD_ACTIVITY_GAME = 0,
    DISCORD_ACTIVITY_STREAMING = 1,
    DISCORD_ACTIVITY_LISTENING = 2,
    DISCORD_ACTIVITY_WATCHING = 3,
    DISCORD_ACTIVITY_CUSTOM = 4,
    DISCORD_ACTIVITY_COMPETING = 5
};
struct discord_activity {
 
    char * name;
 
    enum discord_activity_types type;
 
    char * url;
 
 
    u64unix_ms created_at;
 
 
    struct discord_activity_timestamps * timestamps;
 
 
    u64snowflake application_id;
 
 
    char * details;
 
 
    char * state;
 
 
    struct discord_activity_emoji * emoji;
 
 
    struct discord_activity_party * party;
 
 
    struct discord_activity_assets * assets;
 
 
    struct discord_activity_secrets * secrets;
 
    bool instance;
    u64bitmask flags;
 
    struct discord_activity_buttons * buttons;
 
};
struct discord_activities { int size;
    struct discord_activity *array;
int realsize; };
struct discord_activity_timestamps {
    u64unix_ms start;
    u64unix_ms end;
};
struct discord_activity_emoji {
    char * name;
    u64snowflake id;
    bool animated;
};
struct discord_activity_party {
    char * id;
    struct integers * size;
};
struct discord_activity_assets {
    char * large_image;
    char * large_text;
    char * small_image;
    char * small_text;
};
struct discord_activity_secrets {
    char * join;
    char * spectate;
    char * match;
};
struct discord_activity_button {
    char * label;
    char * url;
};
struct discord_activity_buttons { int size;
    struct discord_activity_button *array;
int realsize; };
struct discord_presence_update {
 
    struct discord_user * user;
 
 
    u64snowflake guild_id;
 
 
    char * status;
 
 
    struct discord_client_status * client_status;
 
 
    struct discord_activities * activities;
 
 
    u64unix_ms since;
 
    bool afk;
};
struct discord_client_status {
    char * desktop;
    char * mobile;
    char * web;
};
struct discord_presence_updates { int size;
    struct discord_presence_update *array;
int realsize; };
struct discord_identify {
    char * token;
    struct discord_identify_connection * properties;
    bool compress;
    int large_threshold;
 
    struct integers * shard;
 
 
    struct discord_presence_update * presence;
 
    u64bitmask intents;
};
struct discord_identify_connection {
    char * os;
    char * browser;
    char * device;
};
struct discord_resume {
    char * token;
    char * session_id;
    int seq;
};
struct discord_request_guild_members {
    u64snowflake guild_id;
    char * query;
    int limit;
    bool presences;
 
    struct snowflakes * user_ids;
 
 
    char * nonce;
 
};
struct discord_update_voice_state {
    u64snowflake guild_id;
    u64snowflake channel_id;
    bool self_mute;
    bool self_deaf;
};
struct discord_ready {
    int v;
    struct discord_user * user;
    struct discord_guilds * guilds;
    char * session_id;
    struct integers * shard;
    struct discord_application * application;
};
struct discord_auto_moderation_action_execution {
    u64snowflake guild_id;
    struct discord_auto_moderation_action * action;
    enum discord_auto_moderation_trigger_types rule_trigger_type;
    u64snowflake user_id;
    u64snowflake channel_id;
    u64snowflake message_id;
    u64snowflake alert_system_message_id;
    char * content;
    char * matched_keyword;
    char * matched_content;
};
struct discord_thread_list_sync {
    u64snowflake guild_id;
    struct snowflakes * channel_ids;
    struct discord_channels * threads;
    struct discord_thread_members * members;
};
struct discord_thread_members_update {
    u64snowflake id;
    u64snowflake guild_id;
    int member_count;
    struct discord_thread_members * added_members;
    struct snowflakes * removed_member_ids;
};
struct discord_channel_pins_update {
    u64snowflake guild_id;
    u64snowflake channel_id;
    u64unix_ms last_pin_timestamp;
};
struct discord_guild_ban_add {
    u64snowflake guild_id;
    struct discord_user * user;
};
struct discord_guild_ban_remove {
    u64snowflake guild_id;
    struct discord_user * user;
};
struct discord_guild_emojis_update {
    u64snowflake guild_id;
    struct discord_emojis * emojis;
};
struct discord_guild_stickers_update {
    u64snowflake guild_id;
    struct discord_stickers * stickers;
};
struct discord_guild_integrations_update {
    u64snowflake guild_id;
};
struct discord_guild_member_remove {
    u64snowflake guild_id;
    struct discord_user * user;
};
struct discord_guild_member_update {
    u64snowflake guild_id;
    struct snowflakes * roles;
    struct discord_user * user;
    char * nick;
    char * avatar;
    u64unix_ms joined_at;
    u64unix_ms premium_since;
    bool deaf;
    bool mute;
    bool pending;
    u64unix_ms communication_disabled_until;
};
struct discord_guild_members_chunk {
    u64snowflake guild_id;
    struct discord_guild_members * members;
    int chunk_index;
    int chunk_count;
    struct snowflakes * not_found;
    struct discord_presence_updates * presences;
    char * nonce;
};
struct discord_guild_role_create {
    u64snowflake guild_id;
    struct discord_role * role;
};
struct discord_guild_role_update {
    u64snowflake guild_id;
    struct discord_role * role;
};
struct discord_guild_role_delete {
    u64snowflake guild_id;
    u64snowflake role_id;
};
struct discord_guild_scheduled_event_user_add {
    u64snowflake guild_scheduled_event_id;
    u64snowflake user_id;
    u64snowflake guild_id;
};
struct discord_guild_scheduled_event_user_remove {
    u64snowflake guild_scheduled_event_id;
    u64snowflake user_id;
    u64snowflake guild_id;
};
struct discord_integration_delete {
    u64snowflake id;
    u64snowflake guild_id;
    u64snowflake application_id;
};
struct discord_invite_create {
    u64snowflake channel_id;
    char * code;
    u64unix_ms created_at;
    u64snowflake guild_id;
    struct discord_user * inviter;
    int max_age;
    int max_uses;
    enum discord_invite_target_types target_type;
    struct discord_user * target_user;
    struct discord_application * target_application;
    bool temporary;
    int uses;
};
struct discord_invite_delete {
    u64snowflake channel_id;
    u64snowflake guild_id;
    char * code;
};
struct discord_message_delete {
    u64snowflake id;
    u64snowflake channel_id;
    u64snowflake guild_id;
};
struct discord_message_delete_bulk {
    struct snowflakes * ids;
    u64snowflake channel_id;
    u64snowflake guild_id;
};
struct discord_message_reaction_add {
    u64snowflake user_id;
    u64snowflake channel_id;
    u64snowflake message_id;
    u64snowflake guild_id;
    struct discord_guild_member * member;
    struct discord_emoji * emoji;
};
struct discord_message_reaction_remove {
    u64snowflake user_id;
    u64snowflake channel_id;
    u64snowflake message_id;
    u64snowflake guild_id;
    struct discord_emoji * emoji;
};
struct discord_message_reaction_remove_all {
    u64snowflake channel_id;
    u64snowflake message_id;
    u64snowflake guild_id;
};
struct discord_message_reaction_remove_emoji {
    u64snowflake channel_id;
    u64snowflake guild_id;
    u64snowflake message_id;
    struct discord_emoji * emoji;
};
struct discord_typing_start {
    u64snowflake channel_id;
    u64snowflake guild_id;
    u64snowflake user_id;
    u64unix_ms timestamp;
    struct discord_guild_member * member;
};
struct discord_voice_server_update {
    char * token;
    u64snowflake guild_id;
    char * endpoint;
};
struct discord_webhooks_update {
    u64snowflake guild_id;
    u64snowflake channel_id;
};
struct discord_session_start_limit {
    int total;
    int remaining;
    int reset_after;
    int max_concurrency;
};
struct discord_auth_response {
    struct discord_application * application;
    struct strings * scopes;
    u64unix_ms expires;
    struct discord_user * user;
};
#define DISCORD_PERM_CREATE_INSTANT_INVITE 1 << 0
#define DISCORD_PERM_KICK_MEMBERS 1 << 1
#define DISCORD_PERM_BAN_MEMBERS 1 << 2
#define DISCORD_PERM_ADMINISTRATOR 1 << 3
#define DISCORD_PERM_MANAGE_CHANNELS 1 << 4
#define DISCORD_PERM_MANAGE_GUILD 1 << 5
#define DISCORD_PERM_ADD_REACTIONS 1 << 6
#define DISCORD_PERM_VIEW_AUDIT_LOG 1 << 7
#define DISCORD_PERM_PRIORITY_SPEAKER 1 << 8
#define DISCORD_PERM_STREAM 1 << 9
#define DISCORD_PERM_VIEW_CHANNEL 1 << 10
#define DISCORD_PERM_SEND_MESSAGES 1 << 11
#define DISCORD_PERM_SEND_TTS_MESSAGES 1 << 12
#define DISCORD_PERM_MANAGE_MESSAGES 1 << 13
#define DISCORD_PERM_EMBED_LINKS 1 << 14
#define DISCORD_PERM_ATTACH_FILES 1 << 15
#define DISCORD_PERM_READ_MESSAGE_HISTORY 1 << 16
#define DISCORD_PERM_MENTION_EVERYONE 1 << 17
#define DISCORD_PERM_USE_EXTERNAL_EMOJIS 1 << 18
#define DISCORD_PERM_VIEW_GUILD_INSIGHTS 1 << 19
#define DISCORD_PERM_CONNECT 1 << 20
#define DISCORD_PERM_SPEAK 1 << 21
#define DISCORD_PERM_MUTE_MEMBERS 1 << 22
#define DISCORD_PERM_DEAFEN_MEMBERS 1 << 23
#define DISCORD_PERM_MOVE_MEMBERS 1 << 24
#define DISCORD_PERM_USE_VAD 1 << 25
#define DISCORD_PERM_CHANGE_NICKNAME 1 << 26
#define DISCORD_PERM_MANAGE_NICKNAMES 1 << 27
#define DISCORD_PERM_MANAGE_ROLES 1 << 28
#define DISCORD_PERM_MANAGE_WEBHOOKS 1 << 29
#define DISCORD_PERM_MANAGE_EMOJIS_AND_STICKERS 1 << 30
#define DISCORD_PERM_USE_APPLICATION_COMMANDS 1 << 31
#define DISCORD_PERM_REQUEST_TO_SPEAK 1 << 32
#define DISCORD_PERM_MANAGE_EVENTS 1 << 33
#define DISCORD_PERM_MANAGE_THREADS 1 << 34
#define DISCORD_PERM_CREATE_PUBLIC_THREADS 1 << 35
#define DISCORD_PERM_CREATE_PRIVATE_THREADS 1 << 36
#define DISCORD_PERM_USE_EXTERNAL_STICKERS 1 << 37
#define DISCORD_PERM_SEND_MESSAGES_IN_THREADS 1 << 38
#define DISCORD_PERM_START_EMBEDDED_ACTIVITIES 1 << 39
#define DISCORD_PERM_MODERATE_MEMBERS 1 << 40
struct discord_role {
    u64snowflake id;
    char * name;
    int color;
    bool hoist;
 
    char * icon;
 
 
    char * unicode_emoji;
 
    int position;
    u64bitmask permissions;
    bool managed;
    bool mentionable;
 
    struct discord_role_tag * tags;
 
};
struct discord_roles { int size;
    struct discord_role *array;
int realsize; };
struct discord_role_tag {
 
    u64snowflake bot_id;
 
 
    u64snowflake integration_id;
 
    bool premium_subscribe;
};
enum discord_membership_state {
    DISCORD_MEMBERSHIP_INVITED = 1,
    DISCORD_MEMBERSHIP_ACCEPTED = 2
};
struct discord_team {
    char * icon;
    u64snowflake id;
 
    struct discord_team_members * members;
 
    char * name;
    u64snowflake owner_user_id;
};
struct discord_team_member {
    enum discord_membership_state membership_state;
 
    struct bitmasks * permissions;
 
    u64snowflake team_id;
 
    struct discord_user * user;
 
};
struct discord_team_members { int size;
    struct discord_team_member *array;
int realsize; };
#define DISCORD_VOICE_MICROPHONE 1 << 0
#define DISCORD_VOICE_SOUNDSHARE 1 << 1
#define DISCORD_VOICE_PRIORITY 1 << 2
enum discord_voice_close_opcodes {
    DISCORD_VOICE_CLOSE_REASON_UNKNOWN_OPCODE = 4001,
    DISCORD_VOICE_CLOSE_REASON_DECODE_ERROR = 4002,
    DISCORD_VOICE_CLOSE_REASON_NOT_AUTHENTICATED = 4003,
    DISCORD_VOICE_CLOSE_REASON_AUTHENTICATION_FAILED = 4004,
    DISCORD_VOICE_CLOSE_REASON_ALREADY_AUTHENTICATED = 4005,
    DISCORD_VOICE_CLOSE_REASON_INVALID_SESSION = 4006,
    DISCORD_VOICE_CLOSE_REASON_SESSION_TIMED_OUT = 4009,
    DISCORD_VOICE_CLOSE_REASON_SERVER_NOT_FOUND = 4011,
    DISCORD_VOICE_CLOSE_REASON_UNKNOWN_PROTOCOL = 4012,
    DISCORD_VOICE_CLOSE_REASON_DISCONNECTED = 4014,
    DISCORD_VOICE_CLOSE_REASON_SERVER_CRASH = 4015,
    DISCORD_VOICE_CLOSE_REASON_UNKNOWN_ENCRYPTION_MODE = 4016
};
enum discord_voice_opcodes {
    DISCORD_VOICE_IDENTIFY = 0,
    DISCORD_VOICE_SELECT_PROTOCOL = 1,
    DISCORD_VOICE_READY = 2,
    DISCORD_VOICE_HEARTBEAT = 3,
    DISCORD_VOICE_SESSION_DESCRIPTION = 4,
    DISCORD_VOICE_SPEAKING = 5,
    DISCORD_VOICE_HEARTBEAT_ACK = 6,
    DISCORD_VOICE_RESUME = 7,
    DISCORD_VOICE_HELLO = 8,
    DISCORD_VOICE_RESUMED = 9,
    DISCORD_VOICE_CLIENT_DISCONNECT = 13,
    DISCORD_VOICE_CODEC = 14
};
enum discord_application_command_types {
    DISCORD_APPLICATION_CHAT_INPUT = 1,
    DISCORD_APPLICATION_USER = 2,
    DISCORD_APPLICATION_MESSAGE = 3
};
enum discord_application_command_option_types {
    DISCORD_APPLICATION_OPTION_SUB_COMMAND = 1,
    DISCORD_APPLICATION_OPTION_SUB_COMMAND_GROUP = 2,
    DISCORD_APPLICATION_OPTION_STRING = 3,
    DISCORD_APPLICATION_OPTION_INTEGER = 4,
    DISCORD_APPLICATION_OPTION_BOOLEAN = 5,
    DISCORD_APPLICATION_OPTION_USER = 6,
    DISCORD_APPLICATION_OPTION_CHANNEL = 7,
    DISCORD_APPLICATION_OPTION_ROLE = 8,
    DISCORD_APPLICATION_OPTION_MENTIONABLE = 9,
    DISCORD_APPLICATION_OPTION_NUMBER = 10,
    DISCORD_APPLICATION_OPTION_ATTACHMENT = 11
};
enum discord_application_command_permission_types {
    DISCORD_APPLICATION_PERMISSION_ROLE = 1,
    DISCORD_APPLICATION_PERMISSION_USER = 2,
    DISCORD_APPLICATION_PERMISSION_CHANNEL = 3
};
struct discord_application_command {
 
    u64snowflake id;
 
 
    enum discord_application_command_types type;
 
 
    u64snowflake application_id;
 
 
    u64snowflake guild_id;
 
 
    char * name;
 
 
    char * description;
 
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
 
    bool dm_permission;
 
 
    bool default_permission;
 
 
    u64snowflake version;
 
};
struct discord_application_commands { int size;
    struct discord_application_command *array;
int realsize; };
struct discord_application_command_option {
    enum discord_application_command_option_types type;
    char * name;
    char * description;
 
    bool required;
 
 
    struct discord_application_command_option_choices * choices;
 
 
    struct discord_application_command_options * options;
 
 
    struct integers * channel_types;
 
 
    char * min_value;
 
 
    char * max_value;
 
 
    bool autocomplete;
 
};
struct discord_application_command_options { int size;
    struct discord_application_command_option *array;
int realsize; };
struct discord_application_command_option_choice {
    char * name;
    json_char * value;
};
struct discord_application_command_option_choices { int size;
    struct discord_application_command_option_choice *array;
int realsize; };
struct discord_application_command_interaction_data_option {
    char * name;
    enum discord_application_command_option_types type;
 
    json_char * value;
 
 
    struct discord_application_command_interaction_data_options * options;
 
    bool focused;
};
struct discord_application_command_interaction_data_options { int size;
    struct discord_application_command_interaction_data_option *array;
int realsize; };
struct discord_guild_application_command_permission {
    u64snowflake id;
    u64snowflake application_id;
    u64snowflake guild_id;
    struct discord_application_command_permissions * permissions;
};
struct discord_guild_application_command_permissions { int size;
    struct discord_guild_application_command_permission *array;
int realsize; };
struct discord_application_command_permission {
    u64snowflake id;
    enum discord_application_command_permission_types type;
    bool permission;
};
struct discord_application_command_permissions { int size;
    struct discord_application_command_permission *array;
int realsize; };
struct discord_create_global_application_command {
    char * name;
    char * description;
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
    bool dm_permission;
    bool default_permission;
 
    enum discord_application_command_types type;
 
};
struct discord_edit_global_application_command {
    char * name;
    char * description;
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
    bool dm_permission;
    bool default_permission;
};
struct discord_create_guild_application_command {
    char * name;
    char * description;
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
    bool dm_permission;
    bool default_permission;
 
    enum discord_application_command_types type;
 
};
struct discord_edit_guild_application_command {
    char * name;
    char * description;
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
    bool default_permission;
};
struct discord_bulk_overwrite_guild_application_commands {
    u64snowflake id;
    char * name;
    struct strings * name_localizations;
    char * description;
    struct strings * description_localizations;
 
    struct discord_application_command_options * options;
 
 
    u64bitmask default_member_permissions;
 
    bool dm_permission;
 
    enum discord_application_command_types type;
 
};
enum discord_component_types {
    DISCORD_COMPONENT_ACTION_ROW = 1,
    DISCORD_COMPONENT_BUTTON = 2,
    DISCORD_COMPONENT_SELECT_MENU = 3,
    DISCORD_COMPONENT_TEXT_INPUT = 4
};
enum discord_component_styles {
    DISCORD_BUTTON_PRIMARY = 1,
    DISCORD_BUTTON_SECONDARY = 2,
    DISCORD_BUTTON_SUCCESS = 3,
    DISCORD_BUTTON_DANGER = 4,
    DISCORD_BUTTON_LINK = 5,
    DISCORD_TEXT_SHORT = 1,
    DISCORD_TEXT_PARAGRAPH = 2
};
struct discord_component {
 
    enum discord_component_types type;
 
    char * custom_id;
    bool disabled;
 
    enum discord_component_styles style;
 
    char * label;
 
    struct discord_emoji * emoji;
 
    char * url;
 
    struct discord_select_options * options;
 
    char * placeholder;
 
    int min_values;
 
 
    int max_values;
 
 
    struct discord_components * components;
 
    int min_length;
    int max_length;
    bool required;
    char * value;
};
struct discord_components { int size;
    struct discord_component *array;
int realsize; };
struct discord_select_option {
    char * label;
    char * value;
    char * description;
 
    struct discord_emoji * emoji;
 
    bool Default;
};
struct discord_select_options { int size;
    struct discord_select_option *array;
int realsize; };
enum discord_interaction_types {
    DISCORD_INTERACTION_PING = 1,
    DISCORD_INTERACTION_APPLICATION_COMMAND = 2,
    DISCORD_INTERACTION_MESSAGE_COMPONENT = 3,
    DISCORD_INTERACTION_APPLICATION_COMMAND_AUTOCOMPLETE = 4,
    DISCORD_INTERACTION_MODAL_SUBMIT = 5
};
enum discord_interaction_callback_types {
    DISCORD_INTERACTION_PONG = 1,
    DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE = 4,
    DISCORD_INTERACTION_DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE = 5,
    DISCORD_INTERACTION_DEFERRED_UPDATE_MESSAGE = 6,
    DISCORD_INTERACTION_UPDATE_MESSAGE = 7,
    DISCORD_INTERACTION_APPLICATION_COMMAND_AUTOCOMPLETE_RESULT = 8,
    DISCORD_INTERACTION_MODAL = 9
};
struct discord_interaction {
    u64snowflake id;
    u64snowflake application_id;
    enum discord_interaction_types type;
    struct discord_interaction_data * data;
    u64snowflake guild_id;
    u64snowflake channel_id;
    struct discord_guild_member * member;
    struct discord_user * user;
    char * token;
    int version;
    struct discord_message * message;
    char * locale;
    char * guild_locale;
};
struct discord_interaction_data {
    u64snowflake id;
    char * name;
    enum discord_application_command_types type;
    struct discord_resolved_data * resolved;
    struct discord_application_command_interaction_data_options * options;
    char * custom_id;
    enum discord_component_types component_type;
    struct strings * values;
    u64snowflake target_id;
    struct discord_components * components;
};
struct discord_resolved_data {
    json_char * users;
    json_char * members;
    json_char * roles;
    json_char * channels;
    json_char * messages;
    json_char * attachments;
};
struct discord_message_interaction {
    u64snowflake id;
    enum discord_interaction_types type;
    char * name;
    struct discord_user * user;
    struct discord_guild_member * member;
};
struct discord_interaction_response {
    enum discord_interaction_callback_types type;
 
    struct discord_interaction_callback_data * data;
 
};
struct discord_interaction_callback_data {
 
    struct discord_components * components;
 
 
    bool tts;
 
 
    char * content;
 
 
    struct discord_embeds * embeds;
 
 
    u64bitmask flags;
 
 
    struct discord_attachments * attachments;
 
    struct discord_application_command_option_choices * choices;
    char * custom_id;
    char * title;
};
struct discord_edit_original_interaction_response {
    u64snowflake thread_id;
    char * content;
 
    struct discord_embeds * embeds;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
};
struct discord_create_followup_message {
    bool wait;
    u64snowflake thread_id;
    char * avatar_url;
    bool tts;
 
    struct discord_embeds * embeds;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
 
    u64bitmask flags;
 
};
struct discord_edit_followup_message {
    u64snowflake thread_id;
    char * content;
 
    struct discord_embeds * embeds;
 
 
    struct discord_allowed_mention * allowed_mentions;
 
 
    struct discord_components * components;
 
 
    struct discord_attachments * attachments;
 
};
#include <stddef.h>
#include <stdbool.h>
#define JSMN_STRICT
#define JSMN_HEADER
#include "jsmn.h"
#include "jsmn-find.h"
#define JSONB_HEADER
#include "json-build.h"
#include <inttypes.h>
#include "carray.h"
#include "cog-utils.h"
#include "types.h"
void strings_cleanup(struct strings *self);
   

void json_values_cleanup(struct json_values *self);
   

void snowflakes_cleanup(struct snowflakes *self);
   

void bitmasks_cleanup(struct bitmasks *self);
   

void integers_cleanup(struct integers *self);
   









void discord_application_init(struct discord_application *self); void discord_application_cleanup(struct discord_application *self);
   
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
 
   
 
   
   
   
   
   

void discord_install_params_init(struct discord_install_params *self); void discord_install_params_cleanup(struct discord_install_params *self);
   
   


   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_audit_log_init(struct discord_audit_log *self); void discord_audit_log_cleanup(struct discord_audit_log *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   
 
   
 
   
   
 
   
 
 
   
 
   


   


   
   
   
   
   
   
   
   


   


   
   
   


   


   
   
   
 
   
 


   
   
   
   


   
   
   


   


   
   
   


   
   


 
   
 
 
   
 


   


 
   
 
 
   
 

void discord_auto_moderation_rule_init(struct discord_auto_moderation_rule *self); void discord_auto_moderation_rule_cleanup(struct discord_auto_moderation_rule *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
   
   

void discord_auto_moderation_rules_cleanup(struct discord_auto_moderation_rules *self);
   

void discord_create_auto_moderation_rule_init(struct discord_create_auto_moderation_rule *self); void discord_create_auto_moderation_rule_cleanup(struct discord_create_auto_moderation_rule *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 

void discord_modify_auto_moderation_rule_init(struct discord_modify_auto_moderation_rule *self); void discord_modify_auto_moderation_rule_cleanup(struct discord_modify_auto_moderation_rule *self);
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 


   


   
   

void discord_invite_init(struct discord_invite *self); void discord_invite_cleanup(struct discord_invite *self);
   
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 
 
   
 
 
   
 

void discord_invites_cleanup(struct discord_invites *self);
   


   
   
   
   
 
   
 


 
   
 
   
   
   

void discord_get_invite_init(struct discord_get_invite *self); void discord_get_invite_cleanup(struct discord_get_invite *self);
   
   
 
   
 


   











   
   
   
   
   
   
   
   
   
   
   
   
   


   
   


   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   

void discord_channel_init(struct discord_channel *self); void discord_channel_cleanup(struct discord_channel *self);
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_channels_cleanup(struct discord_channels *self);
   

void discord_message_init(struct discord_message *self); void discord_message_cleanup(struct discord_message *self);
   
   
   
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_messages_cleanup(struct discord_messages *self);
   


   
   


   
   
   
   

void discord_followed_channel_init(struct discord_followed_channel *self); void discord_followed_channel_cleanup(struct discord_followed_channel *self);
   
   


   
   
   


   


   
   
   
   


   


   
   
   
   
   
   

void discord_thread_member_init(struct discord_thread_member *self); void discord_thread_member_cleanup(struct discord_thread_member *self);
   
   
   
   
   

void discord_thread_members_cleanup(struct discord_thread_members *self);
   


   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   

void discord_attachments_cleanup(struct discord_attachments *self);
   

void discord_embed_init(struct discord_embed *self); void discord_embed_cleanup(struct discord_embed *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

void discord_embeds_cleanup(struct discord_embeds *self);
   

void discord_embed_thumbnail_init(struct discord_embed_thumbnail *self); void discord_embed_thumbnail_cleanup(struct discord_embed_thumbnail *self);
   
 
   
 
 
   
 
 
   
 

void discord_embed_video_init(struct discord_embed_video *self); void discord_embed_video_cleanup(struct discord_embed_video *self);
 
   
 
 
   
 
 
   
 
 
   
 

void discord_embed_image_init(struct discord_embed_image *self); void discord_embed_image_cleanup(struct discord_embed_image *self);
   
 
   
 
 
   
 
 
   
 

void discord_embed_provider_init(struct discord_embed_provider *self); void discord_embed_provider_cleanup(struct discord_embed_provider *self);
 
   
 
 
   
 

void discord_embed_author_init(struct discord_embed_author *self); void discord_embed_author_cleanup(struct discord_embed_author *self);
   
 
   
 
 
   
 
 
   
 

void discord_embed_footer_init(struct discord_embed_footer *self); void discord_embed_footer_cleanup(struct discord_embed_footer *self);
   
 
   
 
 
   
 

void discord_embed_field_init(struct discord_embed_field *self); void discord_embed_field_cleanup(struct discord_embed_field *self);
   
   
   

void discord_embed_fields_cleanup(struct discord_embed_fields *self);
   


   
   
   
   


   
   
   
   

void discord_thread_response_body_init(struct discord_thread_response_body *self); void discord_thread_response_body_cleanup(struct discord_thread_response_body *self);
   
   
   

void discord_modify_channel_init(struct discord_modify_channel *self); void discord_modify_channel_cleanup(struct discord_modify_channel *self);
   
   
   
 
   
 
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
 
   
 
   
   


   


 
   
 
 
   
 
 
   
 
 
   
 

void discord_create_message_init(struct discord_create_message *self); void discord_create_message_cleanup(struct discord_create_message *self);
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


 
   
 
 
   
 

void discord_edit_message_init(struct discord_edit_message *self); void discord_edit_message_cleanup(struct discord_edit_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 


   

void discord_bulk_delete_messages_init(struct discord_bulk_delete_messages *self); void discord_bulk_delete_messages_cleanup(struct discord_bulk_delete_messages *self);
   
   

void discord_edit_channel_permissions_init(struct discord_edit_channel_permissions *self); void discord_edit_channel_permissions_cleanup(struct discord_edit_channel_permissions *self);
   
 
   
 
 
   
 
   

void discord_create_channel_invite_init(struct discord_create_channel_invite *self); void discord_create_channel_invite_cleanup(struct discord_create_channel_invite *self);
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   

void discord_follow_news_channel_init(struct discord_follow_news_channel *self); void discord_follow_news_channel_cleanup(struct discord_follow_news_channel *self);
 
   
 


   


   

void discord_group_dm_add_recipient_init(struct discord_group_dm_add_recipient *self); void discord_group_dm_add_recipient_cleanup(struct discord_group_dm_add_recipient *self);
   
   

void discord_start_thread_with_message_init(struct discord_start_thread_with_message *self); void discord_start_thread_with_message_cleanup(struct discord_start_thread_with_message *self);
   
   
 
   
 
 
   
 

void discord_start_thread_without_message_init(struct discord_start_thread_without_message *self); void discord_start_thread_without_message_cleanup(struct discord_start_thread_without_message *self);
   
   
 
   
 
   
   
 
   
 

void discord_list_active_threads_init(struct discord_list_active_threads *self); void discord_list_active_threads_cleanup(struct discord_list_active_threads *self);
 
   
 
 
   
 
   

void discord_emoji_init(struct discord_emoji *self); void discord_emoji_cleanup(struct discord_emoji *self);
   
   
 
   
 
 
   
 
   
   
   
   

void discord_emojis_cleanup(struct discord_emojis *self);
   

void discord_create_guild_emoji_init(struct discord_create_guild_emoji *self); void discord_create_guild_emoji_cleanup(struct discord_create_guild_emoji *self);
   
   
   
 
   
 

void discord_modify_guild_emoji_init(struct discord_modify_guild_emoji *self); void discord_modify_guild_emoji_cleanup(struct discord_modify_guild_emoji *self);
   
   
   
 
   
 


   






   
   


   
   
   


   
   


   
   
   
   
   


   
   
   
   


   
   
   
   


   
   

void discord_guild_init(struct discord_guild *self); void discord_guild_cleanup(struct discord_guild *self);
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
   

void discord_guilds_cleanup(struct discord_guilds *self);
   

void discord_guild_preview_init(struct discord_guild_preview *self); void discord_guild_preview_cleanup(struct discord_guild_preview *self);
   
   
   
   
   
   
   
   
   
   
   

void discord_guild_widget_settings_init(struct discord_guild_widget_settings *self); void discord_guild_widget_settings_cleanup(struct discord_guild_widget_settings *self);
   
   
   

void discord_guild_widget_init(struct discord_guild_widget *self); void discord_guild_widget_cleanup(struct discord_guild_widget *self);
   
   
   
   
   
   

void discord_guild_member_init(struct discord_guild_member *self); void discord_guild_member_cleanup(struct discord_guild_member *self);
 
   
 
 
   
 
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   
   

void discord_guild_members_cleanup(struct discord_guild_members *self);
   

void discord_integration_init(struct discord_integration *self); void discord_integration_cleanup(struct discord_integration *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_integrations_cleanup(struct discord_integrations *self);
   


   
   


   
   
   
   
   
 
   
 

void discord_ban_init(struct discord_ban *self); void discord_ban_cleanup(struct discord_ban *self);
   
   

void discord_bans_cleanup(struct discord_bans *self);
   

void discord_welcome_screen_init(struct discord_welcome_screen *self); void discord_welcome_screen_cleanup(struct discord_welcome_screen *self);
   
 
   
 


   
   
   
   


   

void discord_prune_count_init(struct discord_prune_count *self); void discord_prune_count_cleanup(struct discord_prune_count *self);
   

void discord_create_guild_init(struct discord_create_guild *self); void discord_create_guild_cleanup(struct discord_create_guild *self);
   
   
 
   
 
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
   
   
   

void discord_modify_guild_init(struct discord_modify_guild *self); void discord_modify_guild_cleanup(struct discord_modify_guild *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_create_guild_channel_init(struct discord_create_guild_channel *self); void discord_create_guild_channel_cleanup(struct discord_create_guild_channel *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
 
   
 
   


   
 
   
 
   
 
   
 

void discord_modify_guild_channel_positions_cleanup(struct discord_modify_guild_channel_positions *self);
   

void discord_list_active_guild_threads_init(struct discord_list_active_guild_threads *self); void discord_list_active_guild_threads_cleanup(struct discord_list_active_guild_threads *self);
   
   


   
   


   
   

void discord_add_guild_member_init(struct discord_add_guild_member *self); void discord_add_guild_member_cleanup(struct discord_add_guild_member *self);
   
   
   
   
   

void discord_modify_guild_member_init(struct discord_modify_guild_member *self); void discord_modify_guild_member_cleanup(struct discord_modify_guild_member *self);
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

void discord_modify_current_member_init(struct discord_modify_current_member *self); void discord_modify_current_member_cleanup(struct discord_modify_current_member *self);
   
 
   
 

void discord_modify_current_user_nick_init(struct discord_modify_current_user_nick *self); void discord_modify_current_user_nick_cleanup(struct discord_modify_current_user_nick *self);
   
 
   
 


   


   


   

void discord_create_guild_ban_init(struct discord_create_guild_ban *self); void discord_create_guild_ban_cleanup(struct discord_create_guild_ban *self);
   
 
   
 


   

void discord_create_guild_role_init(struct discord_create_guild_role *self); void discord_create_guild_role_cleanup(struct discord_create_guild_role *self);
   
   
   
   
   
   
   
   


   
 
   
 

void discord_modify_guild_role_positions_cleanup(struct discord_modify_guild_role_positions *self);
   

void discord_modify_guild_role_init(struct discord_modify_guild_role *self); void discord_modify_guild_role_cleanup(struct discord_modify_guild_role *self);
   
   
   
   
   
   
   
   


   


 
   
 
   

void discord_begin_guild_prune_init(struct discord_begin_guild_prune *self); void discord_begin_guild_prune_cleanup(struct discord_begin_guild_prune *self);
   
 
   
 
   
   


   
 
   
 
   


 
   
 

void discord_modify_guild_welcome_screen_init(struct discord_modify_guild_welcome_screen *self); void discord_modify_guild_welcome_screen_cleanup(struct discord_modify_guild_welcome_screen *self);
   
   
   
 
   
 

void discord_modify_current_user_voice_state_init(struct discord_modify_current_user_voice_state *self); void discord_modify_current_user_voice_state_cleanup(struct discord_modify_current_user_voice_state *self);
   
   
 
   
 

void discord_modify_user_voice_state_init(struct discord_modify_user_voice_state *self); void discord_modify_user_voice_state_cleanup(struct discord_modify_user_voice_state *self);
   
   


   


   
   
   


   
   
   
   

void discord_guild_scheduled_event_init(struct discord_guild_scheduled_event *self); void discord_guild_scheduled_event_cleanup(struct discord_guild_scheduled_event *self);
   
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
   


 
   
 

void discord_guild_scheduled_events_cleanup(struct discord_guild_scheduled_events *self);
   


   
 
   
 
 
   
 

void discord_guild_scheduled_event_users_cleanup(struct discord_guild_scheduled_event_users *self);
   


   

void discord_create_guild_scheduled_event_init(struct discord_create_guild_scheduled_event *self); void discord_create_guild_scheduled_event_cleanup(struct discord_create_guild_scheduled_event *self);
   
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   

void discord_modify_guild_scheduled_event_init(struct discord_modify_guild_scheduled_event *self); void discord_modify_guild_scheduled_event_cleanup(struct discord_modify_guild_scheduled_event *self);
   
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   
   
 
   
 
 
   
 

void discord_guild_template_init(struct discord_guild_template *self); void discord_guild_template_cleanup(struct discord_guild_template *self);
   
   
   
   
   
   
   
   
   
   
   

void discord_guild_templates_cleanup(struct discord_guild_templates *self);
   

void discord_create_guild_from_guild_template_init(struct discord_create_guild_from_guild_template *self); void discord_create_guild_from_guild_template_cleanup(struct discord_create_guild_from_guild_template *self);
   
 
   
 

void discord_create_guild_template_init(struct discord_create_guild_template *self); void discord_create_guild_template_cleanup(struct discord_create_guild_template *self);
   
 
   
 

void discord_modify_guild_template_init(struct discord_modify_guild_template *self); void discord_modify_guild_template_cleanup(struct discord_modify_guild_template *self);
 
   
 
 
   
 


   
   

void discord_stage_instance_init(struct discord_stage_instance *self); void discord_stage_instance_cleanup(struct discord_stage_instance *self);
   
   
   
   
 
   
 
   


   

void discord_create_stage_instance_init(struct discord_create_stage_instance *self); void discord_create_stage_instance_cleanup(struct discord_create_stage_instance *self);
   
   
   
 
   
 

void discord_modify_stage_instance_init(struct discord_modify_stage_instance *self); void discord_modify_stage_instance_cleanup(struct discord_modify_stage_instance *self);
   
   
 
   
 


   


   
   


   
   
   

void discord_sticker_init(struct discord_sticker *self); void discord_sticker_cleanup(struct discord_sticker *self);
   
 
   
 
   
   
   
 
   
 
 
   
 
   
 
   
 
 
   
 
   

void discord_stickers_cleanup(struct discord_stickers *self);
   


   
   
 
   
 


   


   
 
   
 
   
   
 
   
 
   
 
   
 

void discord_sticker_packs_cleanup(struct discord_sticker_packs *self);
   

void discord_list_nitro_sticker_packs_init(struct discord_list_nitro_sticker_packs *self); void discord_list_nitro_sticker_packs_cleanup(struct discord_list_nitro_sticker_packs *self);
   


   
   
   
   
   

void discord_modify_guild_sticker_init(struct discord_modify_guild_sticker *self); void discord_modify_guild_sticker_cleanup(struct discord_modify_guild_sticker *self);
   
   
   


   

















   
   
   


   
   

void discord_user_init(struct discord_user *self); void discord_user_cleanup(struct discord_user *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

void discord_users_cleanup(struct discord_users *self);
   


   
   
   
   
 
   
 
   
   
   
   

void discord_connections_cleanup(struct discord_connections *self);
   

void discord_modify_current_user_init(struct discord_modify_current_user *self); void discord_modify_current_user_cleanup(struct discord_modify_current_user *self);
 
   
 
 
   
 


 
   
 
 
   
 
 
   
 

void discord_create_dm_init(struct discord_create_dm *self); void discord_create_dm_cleanup(struct discord_create_dm *self);
 
   
 

void discord_create_group_dm_init(struct discord_create_group_dm *self); void discord_create_group_dm_cleanup(struct discord_create_group_dm *self);
 
   
 
 
   
 

void discord_voice_state_init(struct discord_voice_state *self); void discord_voice_state_cleanup(struct discord_voice_state *self);
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 

void discord_voice_states_cleanup(struct discord_voice_states *self);
   


   
   
   
   
   

void discord_voice_regions_cleanup(struct discord_voice_regions *self);
   


   
   
   

void discord_webhook_init(struct discord_webhook *self); void discord_webhook_cleanup(struct discord_webhook *self);
   
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   

void discord_webhooks_cleanup(struct discord_webhooks *self);
   

void discord_create_webhook_init(struct discord_create_webhook *self); void discord_create_webhook_cleanup(struct discord_create_webhook *self);
   
   
 
   
 

void discord_modify_webhook_init(struct discord_modify_webhook *self); void discord_modify_webhook_cleanup(struct discord_modify_webhook *self);
   
   
 
   
 
   


   

void discord_modify_webhook_with_token_init(struct discord_modify_webhook_with_token *self); void discord_modify_webhook_with_token_cleanup(struct discord_modify_webhook_with_token *self);
   
 
   
 

void discord_execute_webhook_init(struct discord_execute_webhook *self); void discord_execute_webhook_cleanup(struct discord_execute_webhook *self);
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


 
   
 

void discord_edit_webhook_message_init(struct discord_edit_webhook_message *self); void discord_edit_webhook_message_cleanup(struct discord_edit_webhook_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 


 
   
 






























   
   
   
   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   


 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 


   


   
   


   
   
   


   
   


   
   
   
   


   
   
   


   
   


   

void discord_presence_update_init(struct discord_presence_update *self); void discord_presence_update_cleanup(struct discord_presence_update *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   


   
   
   


   

void discord_identify_init(struct discord_identify *self); void discord_identify_cleanup(struct discord_identify *self);
   
   
   
   
 
   
 
 
   
 
   


   
   
   

void discord_resume_init(struct discord_resume *self); void discord_resume_cleanup(struct discord_resume *self);
   
   
   

void discord_request_guild_members_init(struct discord_request_guild_members *self); void discord_request_guild_members_cleanup(struct discord_request_guild_members *self);
   
   
   
   
 
   
 
 
   
 

void discord_update_voice_state_init(struct discord_update_voice_state *self); void discord_update_voice_state_cleanup(struct discord_update_voice_state *self);
   
   
   
   

void discord_ready_init(struct discord_ready *self); void discord_ready_cleanup(struct discord_ready *self);
   
   
   
   
   
   

void discord_auto_moderation_action_execution_init(struct discord_auto_moderation_action_execution *self); void discord_auto_moderation_action_execution_cleanup(struct discord_auto_moderation_action_execution *self);
   
   
   
   
   
   
   
   
   
   

void discord_thread_list_sync_init(struct discord_thread_list_sync *self); void discord_thread_list_sync_cleanup(struct discord_thread_list_sync *self);
   
   
   
   

void discord_thread_members_update_init(struct discord_thread_members_update *self); void discord_thread_members_update_cleanup(struct discord_thread_members_update *self);
   
   
   
   
   

void discord_channel_pins_update_init(struct discord_channel_pins_update *self); void discord_channel_pins_update_cleanup(struct discord_channel_pins_update *self);
   
   
   

void discord_guild_ban_add_init(struct discord_guild_ban_add *self); void discord_guild_ban_add_cleanup(struct discord_guild_ban_add *self);
   
   

void discord_guild_ban_remove_init(struct discord_guild_ban_remove *self); void discord_guild_ban_remove_cleanup(struct discord_guild_ban_remove *self);
   
   

void discord_guild_emojis_update_init(struct discord_guild_emojis_update *self); void discord_guild_emojis_update_cleanup(struct discord_guild_emojis_update *self);
   
   

void discord_guild_stickers_update_init(struct discord_guild_stickers_update *self); void discord_guild_stickers_update_cleanup(struct discord_guild_stickers_update *self);
   
   

void discord_guild_integrations_update_init(struct discord_guild_integrations_update *self); void discord_guild_integrations_update_cleanup(struct discord_guild_integrations_update *self);
   

void discord_guild_member_remove_init(struct discord_guild_member_remove *self); void discord_guild_member_remove_cleanup(struct discord_guild_member_remove *self);
   
   

void discord_guild_member_update_init(struct discord_guild_member_update *self); void discord_guild_member_update_cleanup(struct discord_guild_member_update *self);
   
   
   
   
   
   
   
   
   
   
   

void discord_guild_members_chunk_init(struct discord_guild_members_chunk *self); void discord_guild_members_chunk_cleanup(struct discord_guild_members_chunk *self);
   
   
   
   
   
   
   

void discord_guild_role_create_init(struct discord_guild_role_create *self); void discord_guild_role_create_cleanup(struct discord_guild_role_create *self);
   
   

void discord_guild_role_update_init(struct discord_guild_role_update *self); void discord_guild_role_update_cleanup(struct discord_guild_role_update *self);
   
   

void discord_guild_role_delete_init(struct discord_guild_role_delete *self); void discord_guild_role_delete_cleanup(struct discord_guild_role_delete *self);
   
   

void discord_guild_scheduled_event_user_add_init(struct discord_guild_scheduled_event_user_add *self); void discord_guild_scheduled_event_user_add_cleanup(struct discord_guild_scheduled_event_user_add *self);
   
   
   

void discord_guild_scheduled_event_user_remove_init(struct discord_guild_scheduled_event_user_remove *self); void discord_guild_scheduled_event_user_remove_cleanup(struct discord_guild_scheduled_event_user_remove *self);
   
   
   

void discord_integration_delete_init(struct discord_integration_delete *self); void discord_integration_delete_cleanup(struct discord_integration_delete *self);
   
   
   

void discord_invite_create_init(struct discord_invite_create *self); void discord_invite_create_cleanup(struct discord_invite_create *self);
   
   
   
   
   
   
   
   
   
   
   
   

void discord_invite_delete_init(struct discord_invite_delete *self); void discord_invite_delete_cleanup(struct discord_invite_delete *self);
   
   
   

void discord_message_delete_init(struct discord_message_delete *self); void discord_message_delete_cleanup(struct discord_message_delete *self);
   
   
   

void discord_message_delete_bulk_init(struct discord_message_delete_bulk *self); void discord_message_delete_bulk_cleanup(struct discord_message_delete_bulk *self);
   
   
   

void discord_message_reaction_add_init(struct discord_message_reaction_add *self); void discord_message_reaction_add_cleanup(struct discord_message_reaction_add *self);
   
   
   
   
   
   

void discord_message_reaction_remove_init(struct discord_message_reaction_remove *self); void discord_message_reaction_remove_cleanup(struct discord_message_reaction_remove *self);
   
   
   
   
   

void discord_message_reaction_remove_all_init(struct discord_message_reaction_remove_all *self); void discord_message_reaction_remove_all_cleanup(struct discord_message_reaction_remove_all *self);
   
   
   

void discord_message_reaction_remove_emoji_init(struct discord_message_reaction_remove_emoji *self); void discord_message_reaction_remove_emoji_cleanup(struct discord_message_reaction_remove_emoji *self);
   
   
   
   

void discord_typing_start_init(struct discord_typing_start *self); void discord_typing_start_cleanup(struct discord_typing_start *self);
   
   
   
   
   

void discord_voice_server_update_init(struct discord_voice_server_update *self); void discord_voice_server_update_cleanup(struct discord_voice_server_update *self);
   
   
   

void discord_webhooks_update_init(struct discord_webhooks_update *self); void discord_webhooks_update_cleanup(struct discord_webhooks_update *self);
   
   

void discord_session_start_limit_init(struct discord_session_start_limit *self); void discord_session_start_limit_cleanup(struct discord_session_start_limit *self);
   
   
   
   

void discord_auth_response_init(struct discord_auth_response *self); void discord_auth_response_cleanup(struct discord_auth_response *self);
   
   
   
   










































void discord_role_init(struct discord_role *self); void discord_role_cleanup(struct discord_role *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
   
 
   
 

void discord_roles_cleanup(struct discord_roles *self);
   


 
   
 
 
   
 
   


   
   

void discord_team_init(struct discord_team *self); void discord_team_cleanup(struct discord_team *self);
   
   
 
   
 
   
   


   
 
   
 
   
 
   
 


   





   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   
   
   
   
   
   
   


   
   
   


   
   
   
   
   
   
   
   
   
   
   


   
   
   

void discord_application_command_init(struct discord_application_command *self); void discord_application_command_cleanup(struct discord_application_command *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

void discord_application_commands_cleanup(struct discord_application_commands *self);
   


   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   


   
   


   


   
   
 
   
 
 
   
 
   


   


   
   
   
   

void discord_guild_application_command_permissions_cleanup(struct discord_guild_application_command_permissions *self);
   

void discord_application_command_permission_init(struct discord_application_command_permission *self); void discord_application_command_permission_cleanup(struct discord_application_command_permission *self);
   
   
   

void discord_application_command_permissions_cleanup(struct discord_application_command_permissions *self);
   

void discord_create_global_application_command_init(struct discord_create_global_application_command *self); void discord_create_global_application_command_cleanup(struct discord_create_global_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

void discord_edit_global_application_command_init(struct discord_edit_global_application_command *self); void discord_edit_global_application_command_cleanup(struct discord_edit_global_application_command *self);
   
   
 
   
 
 
   
 
   
   

void discord_create_guild_application_command_init(struct discord_create_guild_application_command *self); void discord_create_guild_application_command_cleanup(struct discord_create_guild_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

void discord_edit_guild_application_command_init(struct discord_edit_guild_application_command *self); void discord_edit_guild_application_command_cleanup(struct discord_edit_guild_application_command *self);
   
   
 
   
 
 
   
 
   

void discord_bulk_overwrite_guild_application_commands_init(struct discord_bulk_overwrite_guild_application_commands *self); void discord_bulk_overwrite_guild_application_commands_cleanup(struct discord_bulk_overwrite_guild_application_commands *self);
   
   
   
   
   
 
   
 
 
   
 
   
 
   
 


   
   
   
   


   
   
   
   
   
   
   

void discord_component_init(struct discord_component *self); void discord_component_cleanup(struct discord_component *self);
 
   
 
   
   
 
   
 
   
 
   
 
   
 
   
 
   
 
   
 
 
   
 
 
   
 
   
   
   
   

void discord_components_cleanup(struct discord_components *self);
   


   
   
   
 
   
 
   

void discord_select_options_cleanup(struct discord_select_options *self);
   


   
   
   
   
   


   
   
   
   
   
   
   

void discord_interaction_init(struct discord_interaction *self); void discord_interaction_cleanup(struct discord_interaction *self);
   
   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   


   
   
   
   
   

void discord_interaction_response_init(struct discord_interaction_response *self); void discord_interaction_response_cleanup(struct discord_interaction_response *self);
   
 
   
 


 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   

void discord_edit_original_interaction_response_init(struct discord_edit_original_interaction_response *self); void discord_edit_original_interaction_response_cleanup(struct discord_edit_original_interaction_response *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 

void discord_create_followup_message_init(struct discord_create_followup_message *self); void discord_create_followup_message_cleanup(struct discord_create_followup_message *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

void discord_edit_followup_message_init(struct discord_edit_followup_message *self); void discord_edit_followup_message_cleanup(struct discord_edit_followup_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 

long strings_from_jsmnf(jsmnf_pair *root, const char *js, struct strings *self); size_t strings_from_json(const char buf[], size_t size, struct strings *self);
   

long json_values_from_jsmnf(jsmnf_pair *root, const char *js, struct json_values *self); size_t json_values_from_json(const char buf[], size_t size, struct json_values *self);
   

long snowflakes_from_jsmnf(jsmnf_pair *root, const char *js, struct snowflakes *self); size_t snowflakes_from_json(const char buf[], size_t size, struct snowflakes *self);
   

long bitmasks_from_jsmnf(jsmnf_pair *root, const char *js, struct bitmasks *self); size_t bitmasks_from_json(const char buf[], size_t size, struct bitmasks *self);
   

long integers_from_jsmnf(jsmnf_pair *root, const char *js, struct integers *self); size_t integers_from_json(const char buf[], size_t size, struct integers *self);
   









long discord_application_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_application *self); size_t discord_application_from_json(const char buf[], size_t size, struct discord_application *self);
   
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
 
   
 
   
   
   
   
   

long discord_install_params_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_install_params *self); size_t discord_install_params_from_json(const char buf[], size_t size, struct discord_install_params *self);
   
   

long discord_audit_log_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_audit_log *self); size_t discord_audit_log_from_json(const char buf[], size_t size, struct discord_audit_log *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   
 
   
 
   
   
 
   
 
 
   
 
   


   


   
   
   
   
   
   
   
   


   


   
   
   


   


   
   


 
   
 
 
   
 


   


 
   
 
 
   
 

long discord_auto_moderation_rule_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_auto_moderation_rule *self); size_t discord_auto_moderation_rule_from_json(const char buf[], size_t size, struct discord_auto_moderation_rule *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
   
   

long discord_auto_moderation_rules_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_auto_moderation_rules *self); size_t discord_auto_moderation_rules_from_json(const char buf[], size_t size, struct discord_auto_moderation_rules *self);
   

long discord_create_auto_moderation_rule_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_auto_moderation_rule *self); size_t discord_create_auto_moderation_rule_from_json(const char buf[], size_t size, struct discord_create_auto_moderation_rule *self);
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 

long discord_modify_auto_moderation_rule_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_auto_moderation_rule *self); size_t discord_modify_auto_moderation_rule_from_json(const char buf[], size_t size, struct discord_modify_auto_moderation_rule *self);
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 

long discord_invite_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_invite *self); size_t discord_invite_from_json(const char buf[], size_t size, struct discord_invite *self);
   
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 
 
   
 
 
   
 

long discord_invites_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_invites *self); size_t discord_invites_from_json(const char buf[], size_t size, struct discord_invites *self);
   


   
   
   
   
 
   
 


 
   
 
   
   
   

long discord_get_invite_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_get_invite *self); size_t discord_get_invite_from_json(const char buf[], size_t size, struct discord_get_invite *self);
   
   
 
   
 










long discord_channel_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_channel *self); size_t discord_channel_from_json(const char buf[], size_t size, struct discord_channel *self);
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

long discord_channels_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_channels *self); size_t discord_channels_from_json(const char buf[], size_t size, struct discord_channels *self);
   

long discord_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message *self); size_t discord_message_from_json(const char buf[], size_t size, struct discord_message *self);
   
   
   
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

long discord_messages_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_messages *self); size_t discord_messages_from_json(const char buf[], size_t size, struct discord_messages *self);
   


   
   


   
   
   
   

long discord_followed_channel_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_followed_channel *self); size_t discord_followed_channel_from_json(const char buf[], size_t size, struct discord_followed_channel *self);
   
   


   
   
   


   


   
   
   
   


   


   
   
   
   
   
   

long discord_thread_member_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_thread_member *self); size_t discord_thread_member_from_json(const char buf[], size_t size, struct discord_thread_member *self);
   
   
   
   
   

long discord_thread_members_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_thread_members *self); size_t discord_thread_members_from_json(const char buf[], size_t size, struct discord_thread_members *self);
   


   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   

long discord_attachments_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_attachments *self); size_t discord_attachments_from_json(const char buf[], size_t size, struct discord_attachments *self);
   

long discord_embed_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed *self); size_t discord_embed_from_json(const char buf[], size_t size, struct discord_embed *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_embeds_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embeds *self); size_t discord_embeds_from_json(const char buf[], size_t size, struct discord_embeds *self);
   

long discord_embed_thumbnail_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_thumbnail *self); size_t discord_embed_thumbnail_from_json(const char buf[], size_t size, struct discord_embed_thumbnail *self);
   
 
   
 
 
   
 
 
   
 

long discord_embed_video_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_video *self); size_t discord_embed_video_from_json(const char buf[], size_t size, struct discord_embed_video *self);
 
   
 
 
   
 
 
   
 
 
   
 

long discord_embed_image_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_image *self); size_t discord_embed_image_from_json(const char buf[], size_t size, struct discord_embed_image *self);
   
 
   
 
 
   
 
 
   
 

long discord_embed_provider_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_provider *self); size_t discord_embed_provider_from_json(const char buf[], size_t size, struct discord_embed_provider *self);
 
   
 
 
   
 

long discord_embed_author_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_author *self); size_t discord_embed_author_from_json(const char buf[], size_t size, struct discord_embed_author *self);
   
 
   
 
 
   
 
 
   
 

long discord_embed_footer_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_footer *self); size_t discord_embed_footer_from_json(const char buf[], size_t size, struct discord_embed_footer *self);
   
 
   
 
 
   
 

long discord_embed_field_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_field *self); size_t discord_embed_field_from_json(const char buf[], size_t size, struct discord_embed_field *self);
   
   
   

long discord_embed_fields_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_embed_fields *self); size_t discord_embed_fields_from_json(const char buf[], size_t size, struct discord_embed_fields *self);
   


   
   
   
   


   
   
   
   

long discord_thread_response_body_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_thread_response_body *self); size_t discord_thread_response_body_from_json(const char buf[], size_t size, struct discord_thread_response_body *self);
   
   
   

long discord_modify_channel_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_channel *self); size_t discord_modify_channel_from_json(const char buf[], size_t size, struct discord_modify_channel *self);
   
   
 
   
 
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
 
   
 
   
   

long discord_create_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_message *self); size_t discord_create_message_from_json(const char buf[], size_t size, struct discord_create_message *self);
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_edit_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_message *self); size_t discord_edit_message_from_json(const char buf[], size_t size, struct discord_edit_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 

long discord_bulk_delete_messages_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_bulk_delete_messages *self); size_t discord_bulk_delete_messages_from_json(const char buf[], size_t size, struct discord_bulk_delete_messages *self);
   

long discord_edit_channel_permissions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_channel_permissions *self); size_t discord_edit_channel_permissions_from_json(const char buf[], size_t size, struct discord_edit_channel_permissions *self);
 
   
 
 
   
 
   

long discord_create_channel_invite_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_channel_invite *self); size_t discord_create_channel_invite_from_json(const char buf[], size_t size, struct discord_create_channel_invite *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_follow_news_channel_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_follow_news_channel *self); size_t discord_follow_news_channel_from_json(const char buf[], size_t size, struct discord_follow_news_channel *self);
 
   
 

long discord_group_dm_add_recipient_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_group_dm_add_recipient *self); size_t discord_group_dm_add_recipient_from_json(const char buf[], size_t size, struct discord_group_dm_add_recipient *self);
   
   

long discord_start_thread_with_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_start_thread_with_message *self); size_t discord_start_thread_with_message_from_json(const char buf[], size_t size, struct discord_start_thread_with_message *self);
   
 
   
 
 
   
 

long discord_start_thread_without_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_start_thread_without_message *self); size_t discord_start_thread_without_message_from_json(const char buf[], size_t size, struct discord_start_thread_without_message *self);
   
 
   
 
   
   
 
   
 

long discord_list_active_threads_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_list_active_threads *self); size_t discord_list_active_threads_from_json(const char buf[], size_t size, struct discord_list_active_threads *self);
 
   
 
 
   
 
   

long discord_emoji_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_emoji *self); size_t discord_emoji_from_json(const char buf[], size_t size, struct discord_emoji *self);
   
   
 
   
 
 
   
 
   
   
   
   

long discord_emojis_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_emojis *self); size_t discord_emojis_from_json(const char buf[], size_t size, struct discord_emojis *self);
   

long discord_create_guild_emoji_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_emoji *self); size_t discord_create_guild_emoji_from_json(const char buf[], size_t size, struct discord_create_guild_emoji *self);
   
   
 
   
 

long discord_modify_guild_emoji_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_emoji *self); size_t discord_modify_guild_emoji_from_json(const char buf[], size_t size, struct discord_modify_guild_emoji *self);
   
   
 
   
 





long discord_guild_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild *self); size_t discord_guild_from_json(const char buf[], size_t size, struct discord_guild *self);
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
   

long discord_guilds_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guilds *self); size_t discord_guilds_from_json(const char buf[], size_t size, struct discord_guilds *self);
   

long discord_guild_preview_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_preview *self); size_t discord_guild_preview_from_json(const char buf[], size_t size, struct discord_guild_preview *self);
   
   
   
   
   
   
   
   
   
   
   

long discord_guild_widget_settings_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_widget_settings *self); size_t discord_guild_widget_settings_from_json(const char buf[], size_t size, struct discord_guild_widget_settings *self);
   
   

long discord_guild_widget_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_widget *self); size_t discord_guild_widget_from_json(const char buf[], size_t size, struct discord_guild_widget *self);
   
   
   
   
   
   

long discord_guild_member_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_member *self); size_t discord_guild_member_from_json(const char buf[], size_t size, struct discord_guild_member *self);
 
   
 
 
   
 
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   
   

long discord_guild_members_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_members *self); size_t discord_guild_members_from_json(const char buf[], size_t size, struct discord_guild_members *self);
   

long discord_integration_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_integration *self); size_t discord_integration_from_json(const char buf[], size_t size, struct discord_integration *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

long discord_integrations_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_integrations *self); size_t discord_integrations_from_json(const char buf[], size_t size, struct discord_integrations *self);
   


   
   


   
   
   
   
   
 
   
 

long discord_ban_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_ban *self); size_t discord_ban_from_json(const char buf[], size_t size, struct discord_ban *self);
   
   

long discord_bans_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_bans *self); size_t discord_bans_from_json(const char buf[], size_t size, struct discord_bans *self);
   

long discord_welcome_screen_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_welcome_screen *self); size_t discord_welcome_screen_from_json(const char buf[], size_t size, struct discord_welcome_screen *self);
   
 
   
 


   
   
   
   


   

long discord_prune_count_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_prune_count *self); size_t discord_prune_count_from_json(const char buf[], size_t size, struct discord_prune_count *self);
   

long discord_create_guild_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild *self); size_t discord_create_guild_from_json(const char buf[], size_t size, struct discord_create_guild *self);
   
 
   
 
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
   
   
   

long discord_modify_guild_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild *self); size_t discord_modify_guild_from_json(const char buf[], size_t size, struct discord_modify_guild *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

long discord_create_guild_channel_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_channel *self); size_t discord_create_guild_channel_from_json(const char buf[], size_t size, struct discord_create_guild_channel *self);
   
   
   
 
   
 
 
   
 
   
   
   
 
   
 
   


   
 
   
 
   
 
   
 

long discord_modify_guild_channel_positions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_channel_positions *self); size_t discord_modify_guild_channel_positions_from_json(const char buf[], size_t size, struct discord_modify_guild_channel_positions *self);
   

long discord_list_active_guild_threads_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_list_active_guild_threads *self); size_t discord_list_active_guild_threads_from_json(const char buf[], size_t size, struct discord_list_active_guild_threads *self);
   
   

long discord_add_guild_member_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_add_guild_member *self); size_t discord_add_guild_member_from_json(const char buf[], size_t size, struct discord_add_guild_member *self);
   
   
   
   
   

long discord_modify_guild_member_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_member *self); size_t discord_modify_guild_member_from_json(const char buf[], size_t size, struct discord_modify_guild_member *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_modify_current_member_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_current_member *self); size_t discord_modify_current_member_from_json(const char buf[], size_t size, struct discord_modify_current_member *self);
 
   
 

long discord_modify_current_user_nick_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_current_user_nick *self); size_t discord_modify_current_user_nick_from_json(const char buf[], size_t size, struct discord_modify_current_user_nick *self);
 
   
 

long discord_create_guild_ban_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_ban *self); size_t discord_create_guild_ban_from_json(const char buf[], size_t size, struct discord_create_guild_ban *self);
 
   
 

long discord_create_guild_role_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_role *self); size_t discord_create_guild_role_from_json(const char buf[], size_t size, struct discord_create_guild_role *self);
   
   
   
   
   
   
   


   
 
   
 

long discord_modify_guild_role_positions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_role_positions *self); size_t discord_modify_guild_role_positions_from_json(const char buf[], size_t size, struct discord_modify_guild_role_positions *self);
   

long discord_modify_guild_role_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_role *self); size_t discord_modify_guild_role_from_json(const char buf[], size_t size, struct discord_modify_guild_role *self);
   
   
   
   
   
   
   

long discord_begin_guild_prune_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_begin_guild_prune *self); size_t discord_begin_guild_prune_from_json(const char buf[], size_t size, struct discord_begin_guild_prune *self);
 
   
 
   
   

long discord_modify_guild_welcome_screen_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_welcome_screen *self); size_t discord_modify_guild_welcome_screen_from_json(const char buf[], size_t size, struct discord_modify_guild_welcome_screen *self);
   
   
 
   
 

long discord_modify_current_user_voice_state_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_current_user_voice_state *self); size_t discord_modify_current_user_voice_state_from_json(const char buf[], size_t size, struct discord_modify_current_user_voice_state *self);
   
   
 
   
 

long discord_modify_user_voice_state_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_user_voice_state *self); size_t discord_modify_user_voice_state_from_json(const char buf[], size_t size, struct discord_modify_user_voice_state *self);
   
   

long discord_guild_scheduled_event_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_scheduled_event *self); size_t discord_guild_scheduled_event_from_json(const char buf[], size_t size, struct discord_guild_scheduled_event *self);
   
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
   


 
   
 

long discord_guild_scheduled_events_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_scheduled_events *self); size_t discord_guild_scheduled_events_from_json(const char buf[], size_t size, struct discord_guild_scheduled_events *self);
   


   
 
   
 
 
   
 

long discord_guild_scheduled_event_users_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_scheduled_event_users *self); size_t discord_guild_scheduled_event_users_from_json(const char buf[], size_t size, struct discord_guild_scheduled_event_users *self);
   

long discord_create_guild_scheduled_event_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_scheduled_event *self); size_t discord_create_guild_scheduled_event_from_json(const char buf[], size_t size, struct discord_create_guild_scheduled_event *self);
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_modify_guild_scheduled_event_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_scheduled_event *self); size_t discord_modify_guild_scheduled_event_from_json(const char buf[], size_t size, struct discord_modify_guild_scheduled_event *self);
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_guild_template_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_template *self); size_t discord_guild_template_from_json(const char buf[], size_t size, struct discord_guild_template *self);
   
   
   
   
   
   
   
   
   
   
   

long discord_guild_templates_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_templates *self); size_t discord_guild_templates_from_json(const char buf[], size_t size, struct discord_guild_templates *self);
   

long discord_create_guild_from_guild_template_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_from_guild_template *self); size_t discord_create_guild_from_guild_template_from_json(const char buf[], size_t size, struct discord_create_guild_from_guild_template *self);
   
 
   
 

long discord_create_guild_template_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_template *self); size_t discord_create_guild_template_from_json(const char buf[], size_t size, struct discord_create_guild_template *self);
   
 
   
 

long discord_modify_guild_template_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_template *self); size_t discord_modify_guild_template_from_json(const char buf[], size_t size, struct discord_modify_guild_template *self);
 
   
 
 
   
 

long discord_stage_instance_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_stage_instance *self); size_t discord_stage_instance_from_json(const char buf[], size_t size, struct discord_stage_instance *self);
   
   
   
   
 
   
 
   


   

long discord_create_stage_instance_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_stage_instance *self); size_t discord_create_stage_instance_from_json(const char buf[], size_t size, struct discord_create_stage_instance *self);
   
   
 
   
 

long discord_modify_stage_instance_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_stage_instance *self); size_t discord_modify_stage_instance_from_json(const char buf[], size_t size, struct discord_modify_stage_instance *self);
   
 
   
 

long discord_sticker_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_sticker *self); size_t discord_sticker_from_json(const char buf[], size_t size, struct discord_sticker *self);
   
 
   
 
   
   
   
 
   
 
 
   
 
   
 
   
 
 
   
 
   

long discord_stickers_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_stickers *self); size_t discord_stickers_from_json(const char buf[], size_t size, struct discord_stickers *self);
   


   
   
 
   
 


   


   
 
   
 
   
   
 
   
 
   
 
   
 

long discord_sticker_packs_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_sticker_packs *self); size_t discord_sticker_packs_from_json(const char buf[], size_t size, struct discord_sticker_packs *self);
   

long discord_list_nitro_sticker_packs_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_list_nitro_sticker_packs *self); size_t discord_list_nitro_sticker_packs_from_json(const char buf[], size_t size, struct discord_list_nitro_sticker_packs *self);
   

long discord_modify_guild_sticker_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_guild_sticker *self); size_t discord_modify_guild_sticker_from_json(const char buf[], size_t size, struct discord_modify_guild_sticker *self);
   
   
   
















long discord_user_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_user *self); size_t discord_user_from_json(const char buf[], size_t size, struct discord_user *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

long discord_users_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_users *self); size_t discord_users_from_json(const char buf[], size_t size, struct discord_users *self);
   


   
   
   
   
 
   
 
   
   
   
   

long discord_connections_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_connections *self); size_t discord_connections_from_json(const char buf[], size_t size, struct discord_connections *self);
   

long discord_modify_current_user_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_current_user *self); size_t discord_modify_current_user_from_json(const char buf[], size_t size, struct discord_modify_current_user *self);
 
   
 
 
   
 

long discord_create_dm_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_dm *self); size_t discord_create_dm_from_json(const char buf[], size_t size, struct discord_create_dm *self);
 
   
 

long discord_create_group_dm_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_group_dm *self); size_t discord_create_group_dm_from_json(const char buf[], size_t size, struct discord_create_group_dm *self);
 
   
 
 
   
 

long discord_voice_state_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_voice_state *self); size_t discord_voice_state_from_json(const char buf[], size_t size, struct discord_voice_state *self);
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 

long discord_voice_states_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_voice_states *self); size_t discord_voice_states_from_json(const char buf[], size_t size, struct discord_voice_states *self);
   


   
   
   
   
   

long discord_voice_regions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_voice_regions *self); size_t discord_voice_regions_from_json(const char buf[], size_t size, struct discord_voice_regions *self);
   

long discord_webhook_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_webhook *self); size_t discord_webhook_from_json(const char buf[], size_t size, struct discord_webhook *self);
   
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   

long discord_webhooks_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_webhooks *self); size_t discord_webhooks_from_json(const char buf[], size_t size, struct discord_webhooks *self);
   

long discord_create_webhook_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_webhook *self); size_t discord_create_webhook_from_json(const char buf[], size_t size, struct discord_create_webhook *self);
   
 
   
 

long discord_modify_webhook_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_webhook *self); size_t discord_modify_webhook_from_json(const char buf[], size_t size, struct discord_modify_webhook *self);
   
 
   
 
   

long discord_modify_webhook_with_token_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_modify_webhook_with_token *self); size_t discord_modify_webhook_with_token_from_json(const char buf[], size_t size, struct discord_modify_webhook_with_token *self);
   
 
   
 

long discord_execute_webhook_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_execute_webhook *self); size_t discord_execute_webhook_from_json(const char buf[], size_t size, struct discord_execute_webhook *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_edit_webhook_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_webhook_message *self); size_t discord_edit_webhook_message_from_json(const char buf[], size_t size, struct discord_edit_webhook_message *self);
   
 
   
 
 
   
 
 
   
 
 
   
 






























 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 


   


   
   


   
   
   


   
   


   
   
   
   


   
   
   


   
   


   

long discord_presence_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_presence_update *self); size_t discord_presence_update_from_json(const char buf[], size_t size, struct discord_presence_update *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   


   
   
   


   

long discord_ready_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_ready *self); size_t discord_ready_from_json(const char buf[], size_t size, struct discord_ready *self);
   
   
   
   
   
   

long discord_auto_moderation_action_execution_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_auto_moderation_action_execution *self); size_t discord_auto_moderation_action_execution_from_json(const char buf[], size_t size, struct discord_auto_moderation_action_execution *self);
   
   
   
   
   
   
   
   
   
   

long discord_thread_list_sync_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_thread_list_sync *self); size_t discord_thread_list_sync_from_json(const char buf[], size_t size, struct discord_thread_list_sync *self);
   
   
   
   

long discord_thread_members_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_thread_members_update *self); size_t discord_thread_members_update_from_json(const char buf[], size_t size, struct discord_thread_members_update *self);
   
   
   
   
   

long discord_channel_pins_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_channel_pins_update *self); size_t discord_channel_pins_update_from_json(const char buf[], size_t size, struct discord_channel_pins_update *self);
   
   
   

long discord_guild_ban_add_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_ban_add *self); size_t discord_guild_ban_add_from_json(const char buf[], size_t size, struct discord_guild_ban_add *self);
   
   

long discord_guild_ban_remove_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_ban_remove *self); size_t discord_guild_ban_remove_from_json(const char buf[], size_t size, struct discord_guild_ban_remove *self);
   
   

long discord_guild_emojis_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_emojis_update *self); size_t discord_guild_emojis_update_from_json(const char buf[], size_t size, struct discord_guild_emojis_update *self);
   
   

long discord_guild_stickers_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_stickers_update *self); size_t discord_guild_stickers_update_from_json(const char buf[], size_t size, struct discord_guild_stickers_update *self);
   
   

long discord_guild_integrations_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_integrations_update *self); size_t discord_guild_integrations_update_from_json(const char buf[], size_t size, struct discord_guild_integrations_update *self);
   

long discord_guild_member_remove_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_member_remove *self); size_t discord_guild_member_remove_from_json(const char buf[], size_t size, struct discord_guild_member_remove *self);
   
   

long discord_guild_member_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_member_update *self); size_t discord_guild_member_update_from_json(const char buf[], size_t size, struct discord_guild_member_update *self);
   
   
   
   
   
   
   
   
   
   
   

long discord_guild_members_chunk_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_members_chunk *self); size_t discord_guild_members_chunk_from_json(const char buf[], size_t size, struct discord_guild_members_chunk *self);
   
   
   
   
   
   
   

long discord_guild_role_create_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_role_create *self); size_t discord_guild_role_create_from_json(const char buf[], size_t size, struct discord_guild_role_create *self);
   
   

long discord_guild_role_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_role_update *self); size_t discord_guild_role_update_from_json(const char buf[], size_t size, struct discord_guild_role_update *self);
   
   

long discord_guild_role_delete_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_role_delete *self); size_t discord_guild_role_delete_from_json(const char buf[], size_t size, struct discord_guild_role_delete *self);
   
   

long discord_guild_scheduled_event_user_add_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_scheduled_event_user_add *self); size_t discord_guild_scheduled_event_user_add_from_json(const char buf[], size_t size, struct discord_guild_scheduled_event_user_add *self);
   
   
   

long discord_guild_scheduled_event_user_remove_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_scheduled_event_user_remove *self); size_t discord_guild_scheduled_event_user_remove_from_json(const char buf[], size_t size, struct discord_guild_scheduled_event_user_remove *self);
   
   
   

long discord_integration_delete_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_integration_delete *self); size_t discord_integration_delete_from_json(const char buf[], size_t size, struct discord_integration_delete *self);
   
   
   

long discord_invite_create_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_invite_create *self); size_t discord_invite_create_from_json(const char buf[], size_t size, struct discord_invite_create *self);
   
   
   
   
   
   
   
   
   
   
   
   

long discord_invite_delete_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_invite_delete *self); size_t discord_invite_delete_from_json(const char buf[], size_t size, struct discord_invite_delete *self);
   
   
   

long discord_message_delete_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_delete *self); size_t discord_message_delete_from_json(const char buf[], size_t size, struct discord_message_delete *self);
   
   
   

long discord_message_delete_bulk_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_delete_bulk *self); size_t discord_message_delete_bulk_from_json(const char buf[], size_t size, struct discord_message_delete_bulk *self);
   
   
   

long discord_message_reaction_add_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_reaction_add *self); size_t discord_message_reaction_add_from_json(const char buf[], size_t size, struct discord_message_reaction_add *self);
   
   
   
   
   
   

long discord_message_reaction_remove_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_reaction_remove *self); size_t discord_message_reaction_remove_from_json(const char buf[], size_t size, struct discord_message_reaction_remove *self);
   
   
   
   
   

long discord_message_reaction_remove_all_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_reaction_remove_all *self); size_t discord_message_reaction_remove_all_from_json(const char buf[], size_t size, struct discord_message_reaction_remove_all *self);
   
   
   

long discord_message_reaction_remove_emoji_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_message_reaction_remove_emoji *self); size_t discord_message_reaction_remove_emoji_from_json(const char buf[], size_t size, struct discord_message_reaction_remove_emoji *self);
   
   
   
   

long discord_typing_start_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_typing_start *self); size_t discord_typing_start_from_json(const char buf[], size_t size, struct discord_typing_start *self);
   
   
   
   
   

long discord_voice_server_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_voice_server_update *self); size_t discord_voice_server_update_from_json(const char buf[], size_t size, struct discord_voice_server_update *self);
   
   
   

long discord_webhooks_update_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_webhooks_update *self); size_t discord_webhooks_update_from_json(const char buf[], size_t size, struct discord_webhooks_update *self);
   
   

long discord_session_start_limit_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_session_start_limit *self); size_t discord_session_start_limit_from_json(const char buf[], size_t size, struct discord_session_start_limit *self);
   
   
   
   

long discord_auth_response_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_auth_response *self); size_t discord_auth_response_from_json(const char buf[], size_t size, struct discord_auth_response *self);
   
   
   
   










































long discord_role_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_role *self); size_t discord_role_from_json(const char buf[], size_t size, struct discord_role *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
   
 
   
 

long discord_roles_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_roles *self); size_t discord_roles_from_json(const char buf[], size_t size, struct discord_roles *self);
   


 
   
 
 
   
 
   

long discord_team_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_team *self); size_t discord_team_from_json(const char buf[], size_t size, struct discord_team *self);
   
   
 
   
 
   
   


   
 
   
 
   
 
   
 


   




long discord_application_command_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_application_command *self); size_t discord_application_command_from_json(const char buf[], size_t size, struct discord_application_command *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_application_commands_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_application_commands *self); size_t discord_application_commands_from_json(const char buf[], size_t size, struct discord_application_commands *self);
   


   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   


   
   


   


   
   
 
   
 
 
   
 
   


   


   
   
   
   

long discord_guild_application_command_permissions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_guild_application_command_permissions *self); size_t discord_guild_application_command_permissions_from_json(const char buf[], size_t size, struct discord_guild_application_command_permissions *self);
   

long discord_application_command_permission_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_application_command_permission *self); size_t discord_application_command_permission_from_json(const char buf[], size_t size, struct discord_application_command_permission *self);
   
   
   

long discord_application_command_permissions_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_application_command_permissions *self); size_t discord_application_command_permissions_from_json(const char buf[], size_t size, struct discord_application_command_permissions *self);
   

long discord_create_global_application_command_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_global_application_command *self); size_t discord_create_global_application_command_from_json(const char buf[], size_t size, struct discord_create_global_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

long discord_edit_global_application_command_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_global_application_command *self); size_t discord_edit_global_application_command_from_json(const char buf[], size_t size, struct discord_edit_global_application_command *self);
   
   
 
   
 
 
   
 
   
   

long discord_create_guild_application_command_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_guild_application_command *self); size_t discord_create_guild_application_command_from_json(const char buf[], size_t size, struct discord_create_guild_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

long discord_edit_guild_application_command_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_guild_application_command *self); size_t discord_edit_guild_application_command_from_json(const char buf[], size_t size, struct discord_edit_guild_application_command *self);
   
   
 
   
 
 
   
 
   

long discord_bulk_overwrite_guild_application_commands_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_bulk_overwrite_guild_application_commands *self); size_t discord_bulk_overwrite_guild_application_commands_from_json(const char buf[], size_t size, struct discord_bulk_overwrite_guild_application_commands *self);
   
   
   
   
   
 
   
 
 
   
 
   
 
   
 

long discord_component_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_component *self); size_t discord_component_from_json(const char buf[], size_t size, struct discord_component *self);
 
   
 
   
   
 
   
 
   
 
   
 
   
 
   
 
   
 
   
 
 
   
 
 
   
 
   
   
   
   

long discord_components_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_components *self); size_t discord_components_from_json(const char buf[], size_t size, struct discord_components *self);
   


   
   
   
 
   
 
   

long discord_select_options_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_select_options *self); size_t discord_select_options_from_json(const char buf[], size_t size, struct discord_select_options *self);
   

long discord_interaction_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_interaction *self); size_t discord_interaction_from_json(const char buf[], size_t size, struct discord_interaction *self);
   
   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   


   
   
   
   
   

long discord_interaction_response_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_interaction_response *self); size_t discord_interaction_response_from_json(const char buf[], size_t size, struct discord_interaction_response *self);
   
 
   
 


 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   

long discord_edit_original_interaction_response_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_original_interaction_response *self); size_t discord_edit_original_interaction_response_from_json(const char buf[], size_t size, struct discord_edit_original_interaction_response *self);
   
 
   
 
 
   
 
 
   
 
 
   
 

long discord_create_followup_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_create_followup_message *self); size_t discord_create_followup_message_from_json(const char buf[], size_t size, struct discord_create_followup_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

long discord_edit_followup_message_from_jsmnf(jsmnf_pair *root, const char *js, struct discord_edit_followup_message *self); size_t discord_edit_followup_message_from_json(const char buf[], size_t size, struct discord_edit_followup_message *self);
   
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode strings_to_jsonb(jsonb *b, char buf[], size_t size, const struct strings *self); size_t strings_to_json(char buf[], size_t size, const struct strings *self);
   

jsonbcode json_values_to_jsonb(jsonb *b, char buf[], size_t size, const struct json_values *self); size_t json_values_to_json(char buf[], size_t size, const struct json_values *self);
   

jsonbcode snowflakes_to_jsonb(jsonb *b, char buf[], size_t size, const struct snowflakes *self); size_t snowflakes_to_json(char buf[], size_t size, const struct snowflakes *self);
   

jsonbcode bitmasks_to_jsonb(jsonb *b, char buf[], size_t size, const struct bitmasks *self); size_t bitmasks_to_json(char buf[], size_t size, const struct bitmasks *self);
   

jsonbcode integers_to_jsonb(jsonb *b, char buf[], size_t size, const struct integers *self); size_t integers_to_json(char buf[], size_t size, const struct integers *self);
   









jsonbcode discord_application_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_application *self); size_t discord_application_to_json(char buf[], size_t size, const struct discord_application *self);
   
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
 
   
 
   
   
   
   
   

jsonbcode discord_install_params_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_install_params *self); size_t discord_install_params_to_json(char buf[], size_t size, const struct discord_install_params *self);
   
   

jsonbcode discord_audit_log_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_audit_log *self); size_t discord_audit_log_to_json(char buf[], size_t size, const struct discord_audit_log *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   
 
   
 
   
   
 
   
 
 
   
 
   


   


   
   
   
   
   
   
   
   


   


   
   
   


   


   
   


 
   
 
 
   
 


   


 
   
 
 
   
 

jsonbcode discord_create_auto_moderation_rule_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_auto_moderation_rule *self); size_t discord_create_auto_moderation_rule_to_json(char buf[], size_t size, const struct discord_create_auto_moderation_rule *self);
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 

jsonbcode discord_modify_auto_moderation_rule_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_auto_moderation_rule *self); size_t discord_modify_auto_moderation_rule_to_json(char buf[], size_t size, const struct discord_modify_auto_moderation_rule *self);
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 

jsonbcode discord_invite_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_invite *self); size_t discord_invite_to_json(char buf[], size_t size, const struct discord_invite *self);
   
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 
 
   
 
 
   
 

jsonbcode discord_invites_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_invites *self); size_t discord_invites_to_json(char buf[], size_t size, const struct discord_invites *self);
   


   
   
   
   
 
   
 


 
   
 
   
   
   

jsonbcode discord_get_invite_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_get_invite *self); size_t discord_get_invite_to_json(char buf[], size_t size, const struct discord_get_invite *self);
   
   
 
   
 










jsonbcode discord_channel_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_channel *self); size_t discord_channel_to_json(char buf[], size_t size, const struct discord_channel *self);
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_channels_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_channels *self); size_t discord_channels_to_json(char buf[], size_t size, const struct discord_channels *self);
   

jsonbcode discord_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_message *self); size_t discord_message_to_json(char buf[], size_t size, const struct discord_message *self);
   
   
   
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_messages_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_messages *self); size_t discord_messages_to_json(char buf[], size_t size, const struct discord_messages *self);
   


   
   


   
   
   
   

jsonbcode discord_followed_channel_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_followed_channel *self); size_t discord_followed_channel_to_json(char buf[], size_t size, const struct discord_followed_channel *self);
   
   


   
   
   


   


   
   
   
   


   


   
   
   
   
   
   

jsonbcode discord_thread_member_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_thread_member *self); size_t discord_thread_member_to_json(char buf[], size_t size, const struct discord_thread_member *self);
   
   
   
   
   

jsonbcode discord_thread_members_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_thread_members *self); size_t discord_thread_members_to_json(char buf[], size_t size, const struct discord_thread_members *self);
   


   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   

jsonbcode discord_attachments_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_attachments *self); size_t discord_attachments_to_json(char buf[], size_t size, const struct discord_attachments *self);
   

jsonbcode discord_embed_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed *self); size_t discord_embed_to_json(char buf[], size_t size, const struct discord_embed *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_embeds_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embeds *self); size_t discord_embeds_to_json(char buf[], size_t size, const struct discord_embeds *self);
   

jsonbcode discord_embed_thumbnail_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_thumbnail *self); size_t discord_embed_thumbnail_to_json(char buf[], size_t size, const struct discord_embed_thumbnail *self);
   
 
   
 
 
   
 
 
   
 

jsonbcode discord_embed_video_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_video *self); size_t discord_embed_video_to_json(char buf[], size_t size, const struct discord_embed_video *self);
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_embed_image_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_image *self); size_t discord_embed_image_to_json(char buf[], size_t size, const struct discord_embed_image *self);
   
 
   
 
 
   
 
 
   
 

jsonbcode discord_embed_provider_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_provider *self); size_t discord_embed_provider_to_json(char buf[], size_t size, const struct discord_embed_provider *self);
 
   
 
 
   
 

jsonbcode discord_embed_author_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_author *self); size_t discord_embed_author_to_json(char buf[], size_t size, const struct discord_embed_author *self);
   
 
   
 
 
   
 
 
   
 

jsonbcode discord_embed_footer_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_footer *self); size_t discord_embed_footer_to_json(char buf[], size_t size, const struct discord_embed_footer *self);
   
 
   
 
 
   
 

jsonbcode discord_embed_field_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_field *self); size_t discord_embed_field_to_json(char buf[], size_t size, const struct discord_embed_field *self);
   
   
   

jsonbcode discord_embed_fields_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_embed_fields *self); size_t discord_embed_fields_to_json(char buf[], size_t size, const struct discord_embed_fields *self);
   


   
   
   
   


   
   
   
   

jsonbcode discord_thread_response_body_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_thread_response_body *self); size_t discord_thread_response_body_to_json(char buf[], size_t size, const struct discord_thread_response_body *self);
   
   
   

jsonbcode discord_modify_channel_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_channel *self); size_t discord_modify_channel_to_json(char buf[], size_t size, const struct discord_modify_channel *self);
   
   
 
   
 
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
 
   
 
   
   

jsonbcode discord_create_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_message *self); size_t discord_create_message_to_json(char buf[], size_t size, const struct discord_create_message *self);
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_edit_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_message *self); size_t discord_edit_message_to_json(char buf[], size_t size, const struct discord_edit_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_bulk_delete_messages_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_bulk_delete_messages *self); size_t discord_bulk_delete_messages_to_json(char buf[], size_t size, const struct discord_bulk_delete_messages *self);
   

jsonbcode discord_edit_channel_permissions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_channel_permissions *self); size_t discord_edit_channel_permissions_to_json(char buf[], size_t size, const struct discord_edit_channel_permissions *self);
 
   
 
 
   
 
   

jsonbcode discord_create_channel_invite_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_channel_invite *self); size_t discord_create_channel_invite_to_json(char buf[], size_t size, const struct discord_create_channel_invite *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_follow_news_channel_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_follow_news_channel *self); size_t discord_follow_news_channel_to_json(char buf[], size_t size, const struct discord_follow_news_channel *self);
 
   
 

jsonbcode discord_group_dm_add_recipient_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_group_dm_add_recipient *self); size_t discord_group_dm_add_recipient_to_json(char buf[], size_t size, const struct discord_group_dm_add_recipient *self);
   
   

jsonbcode discord_start_thread_with_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_start_thread_with_message *self); size_t discord_start_thread_with_message_to_json(char buf[], size_t size, const struct discord_start_thread_with_message *self);
   
 
   
 
 
   
 

jsonbcode discord_start_thread_without_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_start_thread_without_message *self); size_t discord_start_thread_without_message_to_json(char buf[], size_t size, const struct discord_start_thread_without_message *self);
   
 
   
 
   
   
 
   
 

jsonbcode discord_list_active_threads_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_list_active_threads *self); size_t discord_list_active_threads_to_json(char buf[], size_t size, const struct discord_list_active_threads *self);
 
   
 
 
   
 
   

jsonbcode discord_emoji_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_emoji *self); size_t discord_emoji_to_json(char buf[], size_t size, const struct discord_emoji *self);
   
   
 
   
 
 
   
 
   
   
   
   

jsonbcode discord_emojis_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_emojis *self); size_t discord_emojis_to_json(char buf[], size_t size, const struct discord_emojis *self);
   

jsonbcode discord_create_guild_emoji_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_emoji *self); size_t discord_create_guild_emoji_to_json(char buf[], size_t size, const struct discord_create_guild_emoji *self);
   
   
 
   
 

jsonbcode discord_modify_guild_emoji_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_emoji *self); size_t discord_modify_guild_emoji_to_json(char buf[], size_t size, const struct discord_modify_guild_emoji *self);
   
   
 
   
 





jsonbcode discord_guild_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild *self); size_t discord_guild_to_json(char buf[], size_t size, const struct discord_guild *self);
   
   
   
 
   
 
   
   
   
   
 
   
 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
   

jsonbcode discord_guilds_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guilds *self); size_t discord_guilds_to_json(char buf[], size_t size, const struct discord_guilds *self);
   

jsonbcode discord_guild_preview_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_preview *self); size_t discord_guild_preview_to_json(char buf[], size_t size, const struct discord_guild_preview *self);
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_guild_widget_settings_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_widget_settings *self); size_t discord_guild_widget_settings_to_json(char buf[], size_t size, const struct discord_guild_widget_settings *self);
   
   

jsonbcode discord_guild_widget_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_widget *self); size_t discord_guild_widget_to_json(char buf[], size_t size, const struct discord_guild_widget *self);
   
   
   
   
   
   

jsonbcode discord_guild_member_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_member *self); size_t discord_guild_member_to_json(char buf[], size_t size, const struct discord_guild_member *self);
 
   
 
 
   
 
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   
   

jsonbcode discord_guild_members_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_members *self); size_t discord_guild_members_to_json(char buf[], size_t size, const struct discord_guild_members *self);
   

jsonbcode discord_integration_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_integration *self); size_t discord_integration_to_json(char buf[], size_t size, const struct discord_integration *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_integrations_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_integrations *self); size_t discord_integrations_to_json(char buf[], size_t size, const struct discord_integrations *self);
   


   
   


   
   
   
   
   
 
   
 

jsonbcode discord_ban_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_ban *self); size_t discord_ban_to_json(char buf[], size_t size, const struct discord_ban *self);
   
   

jsonbcode discord_bans_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_bans *self); size_t discord_bans_to_json(char buf[], size_t size, const struct discord_bans *self);
   

jsonbcode discord_welcome_screen_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_welcome_screen *self); size_t discord_welcome_screen_to_json(char buf[], size_t size, const struct discord_welcome_screen *self);
   
 
   
 


   
   
   
   


   

jsonbcode discord_prune_count_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_prune_count *self); size_t discord_prune_count_to_json(char buf[], size_t size, const struct discord_prune_count *self);
   

jsonbcode discord_create_guild_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild *self); size_t discord_create_guild_to_json(char buf[], size_t size, const struct discord_create_guild *self);
   
 
   
 
 
   
 
   
   
   
 
   
 
 
   
 
 
   
 
   
   
   

jsonbcode discord_modify_guild_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild *self); size_t discord_modify_guild_to_json(char buf[], size_t size, const struct discord_modify_guild *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_create_guild_channel_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_channel *self); size_t discord_create_guild_channel_to_json(char buf[], size_t size, const struct discord_create_guild_channel *self);
   
   
   
 
   
 
 
   
 
   
   
   
 
   
 
   


   
 
   
 
   
 
   
 

jsonbcode discord_modify_guild_channel_positions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_channel_positions *self); size_t discord_modify_guild_channel_positions_to_json(char buf[], size_t size, const struct discord_modify_guild_channel_positions *self);
   

jsonbcode discord_list_active_guild_threads_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_list_active_guild_threads *self); size_t discord_list_active_guild_threads_to_json(char buf[], size_t size, const struct discord_list_active_guild_threads *self);
   
   

jsonbcode discord_add_guild_member_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_add_guild_member *self); size_t discord_add_guild_member_to_json(char buf[], size_t size, const struct discord_add_guild_member *self);
   
   
   
   
   

jsonbcode discord_modify_guild_member_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_member *self); size_t discord_modify_guild_member_to_json(char buf[], size_t size, const struct discord_modify_guild_member *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_modify_current_member_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_current_member *self); size_t discord_modify_current_member_to_json(char buf[], size_t size, const struct discord_modify_current_member *self);
 
   
 

jsonbcode discord_modify_current_user_nick_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_current_user_nick *self); size_t discord_modify_current_user_nick_to_json(char buf[], size_t size, const struct discord_modify_current_user_nick *self);
 
   
 

jsonbcode discord_create_guild_ban_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_ban *self); size_t discord_create_guild_ban_to_json(char buf[], size_t size, const struct discord_create_guild_ban *self);
 
   
 

jsonbcode discord_create_guild_role_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_role *self); size_t discord_create_guild_role_to_json(char buf[], size_t size, const struct discord_create_guild_role *self);
   
   
   
   
   
   
   


   
 
   
 

jsonbcode discord_modify_guild_role_positions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_role_positions *self); size_t discord_modify_guild_role_positions_to_json(char buf[], size_t size, const struct discord_modify_guild_role_positions *self);
   

jsonbcode discord_modify_guild_role_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_role *self); size_t discord_modify_guild_role_to_json(char buf[], size_t size, const struct discord_modify_guild_role *self);
   
   
   
   
   
   
   

jsonbcode discord_begin_guild_prune_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_begin_guild_prune *self); size_t discord_begin_guild_prune_to_json(char buf[], size_t size, const struct discord_begin_guild_prune *self);
 
   
 
   
   

jsonbcode discord_modify_guild_welcome_screen_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_welcome_screen *self); size_t discord_modify_guild_welcome_screen_to_json(char buf[], size_t size, const struct discord_modify_guild_welcome_screen *self);
   
   
 
   
 

jsonbcode discord_modify_current_user_voice_state_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_current_user_voice_state *self); size_t discord_modify_current_user_voice_state_to_json(char buf[], size_t size, const struct discord_modify_current_user_voice_state *self);
   
   
 
   
 

jsonbcode discord_modify_user_voice_state_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_user_voice_state *self); size_t discord_modify_user_voice_state_to_json(char buf[], size_t size, const struct discord_modify_user_voice_state *self);
   
   

jsonbcode discord_guild_scheduled_event_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_scheduled_event *self); size_t discord_guild_scheduled_event_to_json(char buf[], size_t size, const struct discord_guild_scheduled_event *self);
   
   
   
   
   
   
   
   
 
   
 
 
   
 
 
   
 
   
 
   
 
 
   
 
   
   


 
   
 

jsonbcode discord_guild_scheduled_events_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_scheduled_events *self); size_t discord_guild_scheduled_events_to_json(char buf[], size_t size, const struct discord_guild_scheduled_events *self);
   


   
 
   
 
 
   
 

jsonbcode discord_guild_scheduled_event_users_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_scheduled_event_users *self); size_t discord_guild_scheduled_event_users_to_json(char buf[], size_t size, const struct discord_guild_scheduled_event_users *self);
   

jsonbcode discord_create_guild_scheduled_event_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_scheduled_event *self); size_t discord_create_guild_scheduled_event_to_json(char buf[], size_t size, const struct discord_create_guild_scheduled_event *self);
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_modify_guild_scheduled_event_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_scheduled_event *self); size_t discord_modify_guild_scheduled_event_to_json(char buf[], size_t size, const struct discord_modify_guild_scheduled_event *self);
 
   
 
 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_guild_template_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_template *self); size_t discord_guild_template_to_json(char buf[], size_t size, const struct discord_guild_template *self);
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_guild_templates_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_templates *self); size_t discord_guild_templates_to_json(char buf[], size_t size, const struct discord_guild_templates *self);
   

jsonbcode discord_create_guild_from_guild_template_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_from_guild_template *self); size_t discord_create_guild_from_guild_template_to_json(char buf[], size_t size, const struct discord_create_guild_from_guild_template *self);
   
 
   
 

jsonbcode discord_create_guild_template_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_template *self); size_t discord_create_guild_template_to_json(char buf[], size_t size, const struct discord_create_guild_template *self);
   
 
   
 

jsonbcode discord_modify_guild_template_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_template *self); size_t discord_modify_guild_template_to_json(char buf[], size_t size, const struct discord_modify_guild_template *self);
 
   
 
 
   
 

jsonbcode discord_stage_instance_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_stage_instance *self); size_t discord_stage_instance_to_json(char buf[], size_t size, const struct discord_stage_instance *self);
   
   
   
   
 
   
 
   


   

jsonbcode discord_sticker_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_sticker *self); size_t discord_sticker_to_json(char buf[], size_t size, const struct discord_sticker *self);
   
 
   
 
   
   
   
 
   
 
 
   
 
   
 
   
 
 
   
 
   

jsonbcode discord_stickers_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_stickers *self); size_t discord_stickers_to_json(char buf[], size_t size, const struct discord_stickers *self);
   


   
   
 
   
 


   


   
 
   
 
   
   
 
   
 
   
 
   
 

jsonbcode discord_sticker_packs_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_sticker_packs *self); size_t discord_sticker_packs_to_json(char buf[], size_t size, const struct discord_sticker_packs *self);
   

jsonbcode discord_modify_guild_sticker_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_guild_sticker *self); size_t discord_modify_guild_sticker_to_json(char buf[], size_t size, const struct discord_modify_guild_sticker *self);
   
   
   
















jsonbcode discord_user_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_user *self); size_t discord_user_to_json(char buf[], size_t size, const struct discord_user *self);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

jsonbcode discord_users_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_users *self); size_t discord_users_to_json(char buf[], size_t size, const struct discord_users *self);
   


   
   
   
   
 
   
 
   
   
   
   

jsonbcode discord_connections_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_connections *self); size_t discord_connections_to_json(char buf[], size_t size, const struct discord_connections *self);
   

jsonbcode discord_modify_current_user_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_current_user *self); size_t discord_modify_current_user_to_json(char buf[], size_t size, const struct discord_modify_current_user *self);
 
   
 
 
   
 

jsonbcode discord_create_dm_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_dm *self); size_t discord_create_dm_to_json(char buf[], size_t size, const struct discord_create_dm *self);
 
   
 

jsonbcode discord_create_group_dm_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_group_dm *self); size_t discord_create_group_dm_to_json(char buf[], size_t size, const struct discord_create_group_dm *self);
 
   
 
 
   
 

jsonbcode discord_voice_state_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_voice_state *self); size_t discord_voice_state_to_json(char buf[], size_t size, const struct discord_voice_state *self);
   
   
   
   
   
   
   
   
   
   
   
   
 
   
 

jsonbcode discord_voice_states_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_voice_states *self); size_t discord_voice_states_to_json(char buf[], size_t size, const struct discord_voice_states *self);
   


   
   
   
   
   

jsonbcode discord_voice_regions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_voice_regions *self); size_t discord_voice_regions_to_json(char buf[], size_t size, const struct discord_voice_regions *self);
   

jsonbcode discord_webhook_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_webhook *self); size_t discord_webhook_to_json(char buf[], size_t size, const struct discord_webhook *self);
   
 
   
 
   
   
 
   
 
   
   
   
 
   
 
   

jsonbcode discord_webhooks_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_webhooks *self); size_t discord_webhooks_to_json(char buf[], size_t size, const struct discord_webhooks *self);
   

jsonbcode discord_create_webhook_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_webhook *self); size_t discord_create_webhook_to_json(char buf[], size_t size, const struct discord_create_webhook *self);
   
 
   
 

jsonbcode discord_modify_webhook_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_webhook *self); size_t discord_modify_webhook_to_json(char buf[], size_t size, const struct discord_modify_webhook *self);
   
 
   
 
   

jsonbcode discord_modify_webhook_with_token_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_modify_webhook_with_token *self); size_t discord_modify_webhook_with_token_to_json(char buf[], size_t size, const struct discord_modify_webhook_with_token *self);
   
 
   
 

jsonbcode discord_execute_webhook_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_execute_webhook *self); size_t discord_execute_webhook_to_json(char buf[], size_t size, const struct discord_execute_webhook *self);
   
   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_edit_webhook_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_webhook_message *self); size_t discord_edit_webhook_message_to_json(char buf[], size_t size, const struct discord_edit_webhook_message *self);
   
 
   
 
 
   
 
 
   
 
 
   
 






























 
   
 
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
 
   
 


   


   
   


   
   
   


   
   


   
   
   
   


   
   
   


   
   


   

jsonbcode discord_presence_update_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_presence_update *self); size_t discord_presence_update_to_json(char buf[], size_t size, const struct discord_presence_update *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   


   
   
   


   

jsonbcode discord_identify_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_identify *self); size_t discord_identify_to_json(char buf[], size_t size, const struct discord_identify *self);
   
   
   
   
 
   
 
 
   
 
   


   
   
   

jsonbcode discord_resume_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_resume *self); size_t discord_resume_to_json(char buf[], size_t size, const struct discord_resume *self);
   
   
   

jsonbcode discord_request_guild_members_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_request_guild_members *self); size_t discord_request_guild_members_to_json(char buf[], size_t size, const struct discord_request_guild_members *self);
   
   
   
   
 
   
 
 
   
 

jsonbcode discord_update_voice_state_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_update_voice_state *self); size_t discord_update_voice_state_to_json(char buf[], size_t size, const struct discord_update_voice_state *self);
   
   
   
   

jsonbcode discord_auth_response_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_auth_response *self); size_t discord_auth_response_to_json(char buf[], size_t size, const struct discord_auth_response *self);
   
   
   
   










































jsonbcode discord_role_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_role *self); size_t discord_role_to_json(char buf[], size_t size, const struct discord_role *self);
   
   
   
   
 
   
 
 
   
 
   
   
   
   
 
   
 

jsonbcode discord_roles_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_roles *self); size_t discord_roles_to_json(char buf[], size_t size, const struct discord_roles *self);
   


 
   
 
 
   
 
   

jsonbcode discord_team_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_team *self); size_t discord_team_to_json(char buf[], size_t size, const struct discord_team *self);
   
   
 
   
 
   
   


   
 
   
 
   
 
   
 


   




jsonbcode discord_application_command_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_application_command *self); size_t discord_application_command_to_json(char buf[], size_t size, const struct discord_application_command *self);
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_application_commands_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_application_commands *self); size_t discord_application_commands_to_json(char buf[], size_t size, const struct discord_application_commands *self);
   


   
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 


   


   
   


   


   
   
 
   
 
 
   
 
   


   


   
   
   
   

jsonbcode discord_guild_application_command_permissions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_guild_application_command_permissions *self); size_t discord_guild_application_command_permissions_to_json(char buf[], size_t size, const struct discord_guild_application_command_permissions *self);
   

jsonbcode discord_application_command_permission_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_application_command_permission *self); size_t discord_application_command_permission_to_json(char buf[], size_t size, const struct discord_application_command_permission *self);
   
   
   

jsonbcode discord_application_command_permissions_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_application_command_permissions *self); size_t discord_application_command_permissions_to_json(char buf[], size_t size, const struct discord_application_command_permissions *self);
   

jsonbcode discord_create_global_application_command_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_global_application_command *self); size_t discord_create_global_application_command_to_json(char buf[], size_t size, const struct discord_create_global_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

jsonbcode discord_edit_global_application_command_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_global_application_command *self); size_t discord_edit_global_application_command_to_json(char buf[], size_t size, const struct discord_edit_global_application_command *self);
   
   
 
   
 
 
   
 
   
   

jsonbcode discord_create_guild_application_command_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_guild_application_command *self); size_t discord_create_guild_application_command_to_json(char buf[], size_t size, const struct discord_create_guild_application_command *self);
   
   
 
   
 
 
   
 
   
   
 
   
 

jsonbcode discord_edit_guild_application_command_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_guild_application_command *self); size_t discord_edit_guild_application_command_to_json(char buf[], size_t size, const struct discord_edit_guild_application_command *self);
   
   
 
   
 
 
   
 
   

jsonbcode discord_bulk_overwrite_guild_application_commands_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_bulk_overwrite_guild_application_commands *self); size_t discord_bulk_overwrite_guild_application_commands_to_json(char buf[], size_t size, const struct discord_bulk_overwrite_guild_application_commands *self);
   
   
   
   
   
 
   
 
 
   
 
   
 
   
 

jsonbcode discord_component_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_component *self); size_t discord_component_to_json(char buf[], size_t size, const struct discord_component *self);
 
   
 
   
   
 
   
 
   
 
   
 
   
 
   
 
   
 
   
 
 
   
 
 
   
 
   
   
   
   

jsonbcode discord_components_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_components *self); size_t discord_components_to_json(char buf[], size_t size, const struct discord_components *self);
   


   
   
   
 
   
 
   

jsonbcode discord_select_options_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_select_options *self); size_t discord_select_options_to_json(char buf[], size_t size, const struct discord_select_options *self);
   

jsonbcode discord_interaction_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_interaction *self); size_t discord_interaction_to_json(char buf[], size_t size, const struct discord_interaction *self);
   
   
   
   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   
   
   
   
   


   
   
   
   
   
   


   
   
   
   
   

jsonbcode discord_interaction_response_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_interaction_response *self); size_t discord_interaction_response_to_json(char buf[], size_t size, const struct discord_interaction_response *self);
   
 
   
 


 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 
   
   
   

jsonbcode discord_edit_original_interaction_response_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_original_interaction_response *self); size_t discord_edit_original_interaction_response_to_json(char buf[], size_t size, const struct discord_edit_original_interaction_response *self);
   
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_create_followup_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_create_followup_message *self); size_t discord_create_followup_message_to_json(char buf[], size_t size, const struct discord_create_followup_message *self);
   
   
 
   
 
 
   
 
 
   
 
 
   
 
 
   
 

jsonbcode discord_edit_followup_message_to_jsonb(jsonb *b, char buf[], size_t size, const struct discord_edit_followup_message *self); size_t discord_edit_followup_message_to_json(char buf[], size_t size, const struct discord_edit_followup_message *self);
   
 
   
 
 
   
 
 
   
 
 
   
 

#endif /* DISCORD_CODECS_H */
