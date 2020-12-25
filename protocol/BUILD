load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "mana_proto_lib",
    srcs = [
        "mana.proto",
    ]
)

cc_proto_library(
    name = "msg_proto",
    deps = [":mana_proto_lib"],
)