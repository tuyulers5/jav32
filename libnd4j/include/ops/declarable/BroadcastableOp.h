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
// Created by raver on 6/6/2018.
//

#ifndef LIBND4J_BROADCASTABLEOP_H
#define LIBND4J_BROADCASTABLEOP_H

#include <graph/Context.h>
#include "OpDescriptor.h"
#include "DeclarableOp.h"
#include "DeclarableCustomOp.h"

namespace sd {
    namespace ops {
        class ND4J_EXPORT BroadcastableOp : public DeclarableCustomOp{
        protected:
            Nd4jStatus validateAndExecute(Context& block) override = 0;
        public:
            BroadcastableOp(const char *name, int numTArgs, int numIArgs);

            ShapeList *calculateOutputShape(ShapeList *inputShape, sd::graph::Context& block) override;
        };
    }
}


#endif //LIBND4J_BROADCASTABLEOP_H
