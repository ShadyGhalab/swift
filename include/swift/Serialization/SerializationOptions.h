//===--- SerializationOptions.h - Control swiftmodule emission --*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_SERIALIZATION_SERIALIZATIONOPTIONS_H
#define SWIFT_SERIALIZATION_SERIALIZATIONOPTIONS_H

#include "swift/Basic/LLVM.h"

namespace swift {

  class SerializationOptions {
    SerializationOptions(const SerializationOptions &) = delete;
    void operator=(const SerializationOptions &) = delete;

  public:
    SerializationOptions() = default;
    SerializationOptions(SerializationOptions &&) = default;
    SerializationOptions &operator=(SerializationOptions &&) = default;
    ~SerializationOptions() = default;

    const char *OutputPath = nullptr;
    const char *DocOutputPath = nullptr;

    StringRef GroupInfoPath;
    StringRef ImportedHeader;
    StringRef ModuleLinkName;
    ArrayRef<std::string> ExtraClangOptions;

    struct FileDependency {
      uint64_t Size;
      uint64_t Hash;
      std::string Path;
    };
    ArrayRef<FileDependency> Dependencies;

    bool AutolinkForceLoad = false;
    bool EnableNestedTypeLookupTable = false;
    bool SerializeAllSIL = false;
    bool SerializeOptionsForDebugging = false;
    bool IsSIB = false;
  };

} // end namespace swift
#endif
