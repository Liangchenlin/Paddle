// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/fluid/jit/compilation_unit.h"

namespace paddle {
namespace jit {

void CompilationUnit::AddExecutorFunction(
    const std::string &func_name,
    const std::shared_ptr<FunctionInfo> &info,
    const Name2VariableMap &params_dict,
    const phi::Place &place) {
  function_dict_[func_name] =
      std::make_shared<ExecutorFunction>(info, params_dict, place);
}

void CompilationUnit::AddPEFunction(const std::string &func_name,
                                    const std::shared_ptr<FunctionInfo> &info,
                                    const Name2VariableMap &params_dict,
                                    const phi::Place &place) {
  function_dict_[func_name] =
      std::make_shared<PEFunction>(info, params_dict, place);
}

std::shared_ptr<BaseFunction> CompilationUnit::GetFunction(
    const std::string &name) const {
  return function_dict_.at(name);
}

}  // namespace jit
}  // namespace paddle
