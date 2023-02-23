// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/manual_control/manual_control.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mavsdk/plugin_base.h"

namespace mavsdk {

class System;
class ManualControlImpl;

/**
 * @brief Enable manual control using e.g. a joystick or gamepad.
 */
class ManualControl : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto manual_control = ManualControl(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit ManualControl(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto manual_control = ManualControl(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit ManualControl(std::shared_ptr<System> system); // new

    /**
     * @brief Destructor (internal use only).
     */
    ~ManualControl() override;

    /**
     * @brief Possible results returned for manual control requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request was successful. */
        NoSystem, /**< @brief No system is connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command refused by vehicle. */
        Timeout, /**< @brief Request timed out. */
        InputOutOfRange, /**< @brief Input out of range. */
        InputNotSet, /**< @brief No Input set. */
    };

    /**
     * @brief Stream operator to print information about a `ManualControl::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, ManualControl::Result const& result);

    /**
     * @brief Callback type for asynchronous ManualControl calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Start position control using e.g. joystick input.
     *
     * Requires manual control input to be sent regularly already.
     * Requires a valid position using e.g. GPS, external vision, or optical flow.
     *
     * This function is non-blocking. See 'start_position_control' for the blocking counterpart.
     */
    void start_position_control_async(const ResultCallback callback);

    /**
     * @brief Start position control using e.g. joystick input.
     *
     * Requires manual control input to be sent regularly already.
     * Requires a valid position using e.g. GPS, external vision, or optical flow.
     *
     * This function is blocking. See 'start_position_control_async' for the non-blocking
     * counterpart.
     *
     * @return Result of request.
     */
    Result start_position_control() const;

    /**
     * @brief Start altitude control
     *
     * Requires manual control input to be sent regularly already.
     * Does not require a  valid position e.g. GPS.
     *
     * This function is non-blocking. See 'start_altitude_control' for the blocking counterpart.
     */
    void start_altitude_control_async(const ResultCallback callback);

    /**
     * @brief Start altitude control
     *
     * Requires manual control input to be sent regularly already.
     * Does not require a  valid position e.g. GPS.
     *
     * This function is blocking. See 'start_altitude_control_async' for the non-blocking
     * counterpart.
     *
     * @return Result of request.
     */
    Result start_altitude_control() const;

    /**
     * @brief Set manual control input
     *
     * The manual control input needs to be sent at a rate high enough to prevent
     * triggering of RC loss, a good minimum rate is 10 Hz.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_manual_control_input(float x, float y, float z, float r) const;

    /**
     * @brief Copy constructor.
     */
    ManualControl(const ManualControl& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const ManualControl& operator=(const ManualControl&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<ManualControlImpl> _impl;
};

} // namespace mavsdk