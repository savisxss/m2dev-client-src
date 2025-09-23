#pragma once

#include <vector>
#include <string>
#include <memory>
#include <future>
#include <functional>

struct GuildMarkInfo {
    uint32_t guild_id;
    uint32_t mark_id;
    uint32_t compressed_size;
    uint32_t original_size;
    std::string format;
    uint32_t crc32;
    uint64_t timestamp;
    std::vector<uint8_t> data;

    GuildMarkInfo() : guild_id(0), mark_id(0), compressed_size(0),
                     original_size(0), crc32(0), timestamp(0) {}
};


enum {
    GUILD_MARK_UPLOAD_SUCCESS = 0,
    GUILD_MARK_UPLOAD_INVALID_FORMAT = 1,
    GUILD_MARK_UPLOAD_TOO_LARGE = 2,
    GUILD_MARK_UPLOAD_SERVER_ERROR = 3,
    GUILD_MARK_UPLOAD_NO_PERMISSION = 4,
};

class CGuildMarkClient {
public:
    using UploadCallback = std::function<void(bool success, const std::string& error)>;
    using DownloadCallback = std::function<void(std::shared_ptr<GuildMarkInfo> mark)>;

private:
    std::map<uint32_t, std::shared_ptr<GuildMarkInfo>> m_cached_marks;
    std::map<uint32_t, UploadCallback> m_upload_callbacks;
    std::map<uint32_t, DownloadCallback> m_download_callbacks;

public:
    static CGuildMarkClient& Instance();

    void UploadMark(uint32_t guild_id, const std::vector<uint8_t>& data,
                   const std::string& format, UploadCallback callback);

    void RequestMark(uint32_t guild_id, DownloadCallback callback);
    void DeleteMark(uint32_t guild_id);

    std::shared_ptr<GuildMarkInfo> GetCachedMark(uint32_t guild_id);
    void ClearCache();

    void OnUploadResult(uint32_t guild_id, uint8_t result, uint32_t mark_id);
    void OnMarkData(const GuildMarkInfo& mark);
    void OnMarkUpdate(uint32_t guild_id, uint8_t update_type);

private:
    CGuildMarkClient() = default;
    ~CGuildMarkClient() = default;

    std::vector<uint8_t> DecompressData(const std::vector<uint8_t>& data, uint32_t size);
    bool ValidateImageFormat(const std::vector<uint8_t>& data, const std::string& format);
};