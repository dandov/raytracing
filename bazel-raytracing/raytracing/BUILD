load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "libraytracing",
    srcs = [
        "image.cpp",
    ],
    hdrs = [
        "image.h",
        "ray.h",
        "stb_image.h",
        "stb_image_resize.h",
        "stb_image_write.h",
        "vec3.h",
    ],
    copts = ["-Iraytracing/sfml"],
    deps = [
        "//raytracing/sfml:libsfml_headers",
    ],
)

cc_binary(
    name = "raytracing",
    srcs = ["main.cc"],
    copts = ["-Iraytracing/sfml"],
    deps = [
        ":libraytracing",
        "//raytracing/sfml:libsfml_main",
        "//raytracing/sfml:libsfml_system",
        "//raytracing/sfml:libsfml_graphics",
        "//raytracing/sfml:libsfml_window",
    ],
)