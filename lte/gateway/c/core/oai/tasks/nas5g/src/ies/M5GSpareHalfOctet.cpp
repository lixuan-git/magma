/*
   Copyright 2020 The Magma Authors.
   This source code is licensed under the BSD-style license found in the
   LICENSE file in the root directory of this source tree.
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#include <iostream>
#include <sstream>
#include <cstdint>
#include "lte/gateway/c/core/oai/tasks/nas5g/include/ies/M5GSpareHalfOctet.hpp"
#include "lte/gateway/c/core/oai/tasks/nas5g/include/M5GCommonDefs.h"

namespace magma5g {
SpareHalfOctetMsg::SpareHalfOctetMsg() {};
SpareHalfOctetMsg::~SpareHalfOctetMsg() {};

// Decode SpareHalfOctet IE
int SpareHalfOctetMsg::DecodeSpareHalfOctetMsg(
    SpareHalfOctetMsg* spare_half_octet, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int decoded = 0;

  spare_half_octet->spare = (*buffer & 0xf0) >> 4;
  return (decoded);
};

// Encode SpareHalfOctet IE
int SpareHalfOctetMsg::EncodeSpareHalfOctetMsg(
    SpareHalfOctetMsg* spare_half_octet, uint8_t iei, uint8_t* buffer,
    uint32_t len) {
  int encoded = 0;

  *(buffer) = 0x00 | (spare_half_octet->spare & 0xf) << 4;
  return (encoded);
};
}  // namespace magma5g
