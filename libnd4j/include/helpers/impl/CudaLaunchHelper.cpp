/* ******************************************************************************
 *
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 *  See the NOTICE file distributed with this work for additional
 *  information regarding copyright ownership.
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

//
// Created by raver on 4/5/2018.
//

#include <helpers/CudaLaunchHelper.h>
#include <math/templatemath.h>

namespace sd {
    Triple CudaLaunchHelper::getFlatLaunchParams(Nd4jLong length, int SM, int CORES, int SHARED_MEMORY) {
        // TODO: to be implemented
        Triple triple(1, 2, 3);

        return triple;
    }

    int CudaLaunchHelper::getReductionBlocks(Nd4jLong xLength, int blockSize) {
        int div = xLength / blockSize;
        int can = sd::math::nd4j_max<int>(div, 1);
        if (xLength % blockSize != 0 && xLength > blockSize)
            can++;

        // not more then 512 blocks
        return sd::math::nd4j_min<int>(can, 512);
    }
}
