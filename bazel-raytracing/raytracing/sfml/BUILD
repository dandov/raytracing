load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_import")

filegroup(
  name = "sfml_headers",
  srcs = glob([
      "SFML/*.hpp",
      "SFML/**/*.hpp",
      "SFML/**/*.inl",
  ]),
  visibility = ["//visibility:public"],
)

cc_import(
  name = "libsfml_headers",
  hdrs = [":sfml_headers"],
  visibility = ["//visibility:public"],
)

cc_import(
  name = "libsfml_graphics",
  hdrs = [":sfml_headers"],
  interface_library = "lib/sfml-graphics-d.lib",
  shared_library = "bin/sfml-graphics-d-2.dll",
  visibility = ["//visibility:public"],
)

cc_import(
  name = "libsfml_window",
  hdrs = [":sfml_headers"],
  interface_library = "lib/sfml-window-d.lib",
  shared_library = "bin/sfml-window-d-2.dll",
  visibility = ["//visibility:public"],
)

cc_import(
  name = "libsfml_system",
  hdrs = [":sfml_headers"],
  interface_library = "lib/sfml-system-d.lib",
  shared_library = "bin/sfml-system-d-2.dll",
  visibility = ["//visibility:public"],
)

cc_import(
  name = "libsfml_main",
  hdrs = [":sfml_headers"],
  interface_library = "lib/sfml-main-d.lib",
  system_provided = 1,
  visibility = ["//visibility:public"],
)
