#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <fc/io/json.hpp>
#include <fc/variant.hpp>
#include <rapidjson/document.h>
#include <string>
#include <rapidjson/prettywriter.h>

using namespace std;
using namespace rapidjson;
using namespace fc;

void variant_parser(string& json_str) {
    auto v = json::from_string(json_str, json::parse_type::relaxed_parser, 1);
//    auto s = json::to_pretty_string(v);
//    cout << s << endl;
}

void rapidjson_parser(string& json_str) {
    Document d;
    d.Parse(json_str.c_str());

//    StringBuffer s;
//    Writer<StringBuffer> w(s);
//    d.Accept(w);
//
//    cout << s.GetString() << endl;
}

TEST_CASE("json_parser_test") {
    string json_str = "{\"jsonrpc\": \"2.0\", \"method\": \"eth_getBlockByNumber\", \"id\": 1, \"params\": [\"0x1\", true]}";

    BENCHMARK("variant_parser_benchmark") { variant_parser(json_str); };

    BENCHMARK("rapidjson_parser") { rapidjson_parser(json_str); };
}