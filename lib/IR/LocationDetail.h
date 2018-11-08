//===- LocationDetail.h - MLIR Location storage details ---------*- C++ -*-===//
//
// Copyright 2019 The MLIR Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// =============================================================================
//
// This holds implementation details of Location.
//
//===----------------------------------------------------------------------===//
#ifndef MLIR_IR_LOCATIONDETAIL_H_
#define MLIR_IR_LOCATIONDETAIL_H_

#include "mlir/IR/Location.h"
#include "llvm/ADT/StringRef.h"

namespace mlir {

class MLIRContext;

namespace detail {

/// Base storage class appearing in a Location.
struct alignas(8) LocationStorage {
  LocationStorage(Location::Kind kind) : kind(kind) {}

  /// Classification of the subclass, used for type checking.
  Location::Kind kind : 8;
};

struct UnknownLocationStorage : public LocationStorage {};

struct FileLineColLocationStorage : public LocationStorage {
  const UniquedFilename filename;
  const unsigned line, column;
};

} // end namespace detail
} // end namespace mlir
#endif // MLIR_IR_LOCATIONDETAIL_H_