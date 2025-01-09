#pragma once

#include <utils/object.hpp>

#include <curl/curl.h>

#include <filesystem>
#include <functional>
#include <map>

class HttpClientAsync : noncopyable
{
public:
    using Callback = std::function<void(const std::string &)>;
    using Headers = std::map<std::string, std::string>;

    HttpClientAsync();
    ~HttpClientAsync();

    void get(const std::string &url, const Headers &headers = {}, Callback callback = nullptr);
    void post(const std::string &url,
              const std::string &data,
              const Headers &headers = {},
              Callback callback = nullptr);
    void put(const std::string &url,
             const std::string &data,
             const Headers &headers = {},
             Callback callback = nullptr);
    void del(const std::string &url, const Headers &headers = {}, Callback callback = nullptr);
    void options(const std::string &url, const Headers &headers = {}, Callback callback = nullptr);
    void patch(const std::string &url,
               const std::string &data,
               const Headers &headers = {},
               Callback callback = nullptr);

    void sendCustomRequest(const std::string &url,
                           const std::string &method,
                           const std::string &data,
                           const Headers &headers,
                           Callback callback);

    void download(const std::string &url,
                  const std::filesystem::path &path,
                  const Headers &headers = {},
                  Callback callback = nullptr);
    void upload_put(const std::string &url,
                    const std::filesystem::path &path,
                    const Headers &headers = {},
                    Callback callback = nullptr);
    void upload_post(const std::string &url,
                     const std::filesystem::path &path,
                     const Headers &headers = {},
                     Callback callback = nullptr);

private:
    class HttpClientAsyncPrivate;
    std::unique_ptr<HttpClientAsyncPrivate> d_ptr;
};
