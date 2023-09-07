// This code is released only for internal evaluation.
// No commercial use, editing or copying is allowed.

#include <ze/vio_frontend/frontend_api.hpp>

#include <imp/core/image.hpp>
#include <ze/cameras/camera_rig.hpp>
#include <ze/common/file_utils.hpp>
#include <ze/common/logging.hpp>
#include <ze/common/timer.hpp>
#include <ze/common/transformation.hpp>
#include <ze/common/types.hpp>
#include <ze/vio_common/nframe.hpp>
#include <ze/vio_common/nframe_table.hpp>
#include <ze/vio_common/imu_integrator.hpp>
#include <ze/vio_frontend/frontend_base.hpp>
#include <ze/vio_frontend/frontend_vio.hpp>

namespace ze {

void VisualOdometry::initialize()
{
  // Create frontend.
  std::cout<<"[MESSAGE] Ultimate SLAM vo is initialising...\n";
  frontend_ = std::make_shared<FrontendVio>();
}


void VisualOdometry::startBlocking()
{
 
  frontend_->stage_ = FrontendStage::AttitudeEstimation;

}

void VisualOdometry::shutdown()
{
 
  // CHECK(frontend_);

  frontend_->shutdown();
}

void VisualOdometry::pause()
{

}

void VisualOdometry::registerResultCallback(const VisualOdometryCallback& cb)
{
  // CHECK(frontend_);
  frontend_->registerResultCallback(cb);
}

} // namespace ze
