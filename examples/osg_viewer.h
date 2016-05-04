/**
 This file is part of mesh-deform.
 
 Copyright(C) 2016 Christoph Heindl
 All rights reserved.
 
 This software may be modified and distributed under the terms
 of the BSD license.See the LICENSE file for details.
 */

#ifndef DEFORM_OSG_VIEWER_H
#define DEFORM_OSG_VIEWER_H

#include <deform/mesh.h>
#include <memory>
#include <functional>

namespace deform {
    namespace example {
    
        class OSGViewer {
        public:
            typedef std::function<bool(deform::Mesh *, double)> DeformCallback;
            
            OSGViewer(int argc, char **argv, deform::Mesh *mesh, DeformCallback dc);
            OSGViewer(const OSGViewer &other) = delete;
            OSGViewer &operator=(const OSGViewer &other) = delete;
            ~OSGViewer();
            
            void run();
            
        private:
            
            void setupScene();
            
            struct data;
            std::unique_ptr<data> _data;
        };
    }
}

#endif