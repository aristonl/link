#include <algorithm>
#include <Link.hpp>
#include <iostream>

std::string Link::Status(int status) {
    switch (status) {
        case 200: return "OK";
        case 201: return "Created";
        case 202: return "Accepted";
        case 203: return "Non-Authoritative Information";
        case 204: return "No Content";
        case 205: return "Reset Content";
        case 206: return "Partial Content";
        case 300: return "Multiple Choices";
        case 301: return "Moved Permanently";
        case 302: return "Found";
        case 303: return "See Other";
        case 304: return "Not Modified";
        case 305: return "Use Proxy";
        case 307: return "Temporary Redirect";
        case 400: return "Bad Request";
        case 401: return "Unauthorized";
        case 402: return "Payment Required";
        case 403: return "Forbidden";
        case 404: return "Not Found";
        case 405: return "Method Not Allowed";
        case 406: return "Not Acceptable";
        case 407: return "Proxy Authentication Required";
        case 408: return "Request Timeout";
        case 409: return "Conflict";
        case 410: return "Gone";
        case 411: return "Length Required";
        case 412: return "Precondition Failed";
        case 413: return "Request Entity Too Large";
        case 414: return "Request-URI Too Long";
        case 415: return "Unsupported Media Type";
        case 416: return "Requested Range Not Satisfiable";
        case 417: return "Expectation Failed";
        case 500: return "Internal Server Error";
        case 501: return "Not Implemented";
        case 502: return "Bad Gateway";
        case 503: return "Service Unavailable";
        case 504: return "Gateway Timeout";
        case 505: return "HTTP Version Not Supported";
        default: return "Unknown";
    }
}

std::string Link::GetMIMEType(std::string path) {
    // get the extension
    std::string extension = path.substr(path.find_last_of(".") + 1);
    // convert to lowercase
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    // return the MIME type
    if (extension == "html" || extension == "htm") return "text/html";
    if (extension == "css") return "text/css";
    if (extension == "js") return "application/javascript";
    if (extension == "json") return "application/json";
    if (extension == "xml") return "application/xml";
    if (extension == "png") return "image/png";
    if (extension == "jpg" || extension == "jpeg") return "image/jpeg";
    if (extension == "gif") return "image/gif";
    if (extension == "svg") return "image/svg+xml";
    if (extension == "ico") return "image/x-icon";
    if (extension == "ttf") return "font/ttf";
    if (extension == "otf") return "font/otf";
    if (extension == "woff") return "font/woff";
    if (extension == "woff2") return "font/woff2";
    if (extension == "eot") return "font/eot";
    if (extension == "mp3") return "audio/mpeg";
    if (extension == "wav") return "audio/wav";
    if (extension == "ogg") return "audio/ogg";
    if (extension == "mp4") return "video/mp4";
    if (extension == "webm") return "video/webm";
    if (extension == "ogv") return "video/ogg";
    if (extension == "pdf") return "application/pdf";
    if (extension == "zip") return "application/zip";
    if (extension == "rar") return "application/x-rar-compressed";
    if (extension == "7z") return "application/x-7z-compressed";
    if (extension == "doc") return "application/msword";
    if (extension == "docx") return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    if (extension == "xls") return "application/vnd.ms-excel";
    if (extension == "xlsx") return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    if (extension == "ppt") return "application/vnd.ms-powerpoint";
    if (extension == "pptx") return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    if (extension == "exe") return "application/x-msdownload";
    if (extension == "apk") return "application/vnd.android.package-archive";
    if (extension == "ipa") return "application/octet-stream";
    if (extension == "deb") return "application/x-debian-package";
    if (extension == "rpm") return "application/x-redhat-package-manager";
    if (extension == "tar") return "application/x-tar";
    if (extension == "gz") return "application/gzip";
    if (extension == "bz2") return "application/x-bzip2";
    if (extension == "xz") return "application/x-xz";
    if (extension == "bin") return "application/octet-stream";
    if (extension == "iso") return "application/octet-stream";
    if (extension == "dmg") return "application/octet-stream";
    if (extension == "txt") return "text/plain";
    if (extension == "rtf") return "text/rtf";
    if (extension == "md") return "text/markdown";
    if (extension == "csv") return "text/csv";
    if (extension == "ics") return "text/calendar";
    if (extension == "yml") return "text/yaml";
    if (extension == "yaml") return "text/yaml";
    if (extension == "php") return "text/x-php";
    if (extension == "c") return "text/x-c";
    if (extension == "cpp") return "text/x-c";
    if (extension == "h") return "text/x-c";
    if (extension == "hpp") return "text/x-c";
    if (extension == "java") return "text/x-java-source";
    if (extension == "py") return "text/x-python";
    if (extension == "sh") return "text/x-shellscript";
    if (extension == "bat") return "text/x-shellscript";
    if (extension == "rb") return "text/x-ruby";
    if (extension == "swift") return "text/x-swift";
    if (extension == "go") return "text/x-go";
    if (extension == "pl") return "text/x-perl";
    if (extension == "sql") return "text/x-sql";
    if (extension == "lua") return "text/x-lua";
    if (extension == "diff") return "text/x-diff";
    if (extension == "patch") return "text/x-diff";
    if (extension == "conf") return "text/x-config";
    if (extension == "ini") return "text/x-ini";
    if (extension == "log") return "text/x-log";
    if (extension == "rtx") return "text/richtext";
    if (extension == "tsv") return "text/tab-separated-values";
    if (extension == "jad") return "text/vnd.sun.j2me.app-descriptor";
    if (extension == "wml") return "text/vnd.wap.wml";
    if (extension == "wmls") return "text/vnd.wap.wmlscript";
    if (extension == "vtt") return "text/vtt";
    if (extension == "htc") return "text/x-component";
    if (extension == "f4v") return "video/x-f4v";
    if (extension == "flv") return "video/x-flv";
    if (extension == "m4v") return "video/x-m4v";
    if (extension == "mkv") return "video/x-matroska";
    if (extension == "mov") return "video/quicktime";
    if (extension == "mp2") return "video/mpeg";
    if (extension == "mpg") return "video/mpeg";
    if (extension == "mpeg") return "video/mpeg";
    if (extension == "mpe") return "video/mpeg";
    if (extension == "m2v") return "video/mpeg";
    if (extension == "m4v") return "video/mpeg";
    if (extension == "3gp") return "video/3gpp";
    if (extension == "3g2") return "video/3gpp2";
    if (extension == "asf") return "video/x-ms-asf";
    if (extension == "asx") return "video/x-ms-asf";
    return "application/octet-stream";
}
