/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/planning/common/planning_gflags.h"

DEFINE_bool(planning_test_mode, false, "Enable planning test mode.");

DEFINE_double(test_duration, -1.0,
              "The runtime duration in test mode. There is no runtime limit if "
              "the value is not positive");

DEFINE_int32(planning_loop_rate, 10, "Loop rate for planning node");

DEFINE_string(planning_adapter_config_filename,
              "modules/planning/conf/adapter.conf",
              "The adapter configuration file");

DEFINE_string(smoother_config_file,
              "modules/planning/conf/smoother_config.pb.txt",
              "The configuration file for qp sline smoother");

DEFINE_string(rtk_trajectory_filename, "modules/planning/data/garage.csv",
              "Loop rate for planning node");

DEFINE_uint64(rtk_trajectory_forward, 800,
              "The number of points to be included in RTK trajectory "
              "after the matched point");

DEFINE_double(rtk_trajectory_resolution, 0.01,
              "The time resolution of output trajectory for rtk planner.");

DEFINE_bool(publish_estop, false, "publish estop decision in planning");
DEFINE_bool(enable_trajectory_stitcher, true, "enable stitching trajectory");

DEFINE_double(
    look_backward_distance, 30,
    "look backward this distance when creating reference line from routing");

DEFINE_double(look_forward_short_distance, 150,
              "short look forward this distance when creating reference line "
              "from routing when ADC is slow");
DEFINE_double(
    look_forward_long_distance, 250,
    "look forward this distance when creating reference line from routing");
DEFINE_double(look_forward_time_sec, 8.0,
              "look forward time times adc speed to calculate this distance "
              "when creating reference line from routing");
DEFINE_bool(enable_reference_line_stitching, true,
            "Enable stitching reference line, which can reducing computing "
            "time and improve stability");
DEFINE_double(look_forward_extend_distance, 50,
              "The step size when extending reference line.");
DEFINE_double(reference_line_stitch_overlap_distance, 20,
              "The overlap distance with the existing reference line when "
              "stitching the existing reference line");
DEFINE_double(reference_line_lateral_buffer, 0.5,
              "When creating reference line, the minimum distance with road "
              "curb for a vehicle driving on this line.");
DEFINE_double(prepare_rerouting_time, 2.0,
              "If there are this amount of seconds left to finish driving on "
              "current route, and there is no routing, do rerouting");

DEFINE_double(rerouting_cooldown_time, 0.6,
              "Wait for at least this amount of seconds before send another "
              "rerouting request");

DEFINE_bool(enable_smooth_reference_line, true,
            "enable smooth the map reference line");

DEFINE_double(spiral_smoother_max_deviation, 0.1,
              "The max deviation of spiral reference line smoother.");
DEFINE_int32(spiral_smoother_num_iteration, 1000,
             "The iteration num of spiral reference line smoother.");
DEFINE_double(spiral_smoother_piecewise_length, 10.0,
              "The piecewise length of spiral smoother.");
DEFINE_double(spiral_reference_line_resolution, 0.02,
              "The output resolution for reference line.");
DEFINE_bool(prioritize_change_lane, false,
            "change lane strategy has higher priority, always use a valid "
            "change lane path if such path exists");
DEFINE_bool(reckless_change_lane, false,
            "Always allow the vehicle change lane. The vehicle may continue "
            "changing lane. This is mainly test purpose");
DEFINE_double(change_lane_fail_freeze_time, 3.0,
              "seconds. Not allowed to change lane this amount of time "
              "if it just finished change lane or failed to change lane");
DEFINE_double(change_lane_success_freeze_time, 3.0,
              "seconds. Not allowed to change lane this amount of time "
              "if it just finished change lane or failed to change lane");
DEFINE_double(change_lane_min_length, 30.0,
              "meters. If the change lane target has longer length than this "
              "threshold, it can shortcut the default lane.");
DEFINE_bool(enable_change_lane_decider, false,
            "True to use change lane state machine decider.");
DEFINE_double(change_lane_speed_relax_percentage, 0.05,
              "The percentage of change lane speed relaxation.");
DEFINE_bool(enable_side_vehicle_st_boundary, false,
            "Add st boundary of side vehicle in st graph.");

DEFINE_int32(max_history_frame_num, 1, "The maximum history frame number");

DEFINE_double(max_collision_distance, 0.0,
              "considered as collision if distance (meters) is smaller than or "
              "equal to this (meters)");

DEFINE_double(replan_lateral_distance_threshold, 5.0,
              "The distance threshold of replan");
DEFINE_double(replan_longitudinal_distance_threshold, 5.0,
              "The distance threshold of replan");
DEFINE_bool(estimate_current_vehicle_state, true,
            "Estimate current vehicle state.");

DEFINE_bool(enable_reference_line_provider_thread, true,
            "Enable reference line provider thread.");

DEFINE_double(default_reference_line_width, 4.0,
              "Default reference line width");

DEFINE_double(smoothed_reference_line_max_diff, 5.0,
              "Maximum position difference between the smoothed and the raw "
              "reference lines.");

DEFINE_double(planning_upper_speed_limit, 31.3,
              "Maximum speed (m/s) in planning.");

DEFINE_double(trajectory_time_length, 8.0, "Trajectory time length");

// planning trajectory output time density control
DEFINE_double(
    trajectory_time_min_interval, 0.02,
    "(seconds) Trajectory time interval when publish. The is the min value.");
DEFINE_double(
    trajectory_time_max_interval, 0.1,
    "(seconds) Trajectory time interval when publish. The is the max value.");
DEFINE_double(
    trajectory_time_high_density_period, 1.0,
    "(seconds) Keep high density in the next this amount of seconds. ");

DEFINE_bool(enable_trajectory_check, false,
            "Enable sanity check for planning trajectory.");

DEFINE_double(speed_lower_bound, -0.02, "The lowest speed allowed.");
DEFINE_double(speed_upper_bound, 40.0, "The highest speed allowed.");

DEFINE_double(longitudinal_acceleration_lower_bound, -4.5,
              "The lowest longitudinal acceleration allowed.");
DEFINE_double(longitudinal_acceleration_upper_bound, 4.0,
              "The highest longitudinal acceleration allowed.");
DEFINE_double(lateral_acceleration_bound, 4.0,
              "Bound of lateral acceleration; symmetric for left and right");

DEFINE_double(longitudinal_jerk_lower_bound, -4.0,
              "The lower bound of longitudinal jerk.");
DEFINE_double(longitudinal_jerk_upper_bound, 4.0,
              "The upper bound of longitudinal jerk.");
DEFINE_double(lateral_jerk_bound, 4.0,
              "Bound of lateral jerk; symmetric for left and right");

DEFINE_double(dl_bound, 0.10,
              "The bound for derivative l in s-l coordinate system.");
DEFINE_double(kappa_bound, 0.20, "The bound for trajectory curvature");
DEFINE_double(dkappa_bound, 0.02,
              "The bound for trajectory curvature change rate");

// ST Boundary
DEFINE_double(st_max_s, 100, "the maximum s of st boundary");
DEFINE_double(st_max_t, 8, "the maximum t of st boundary");

// Decision Part
DEFINE_double(static_obstacle_speed_threshold, 2.0,
              "obstacles are considered as static obstacle if its speed is "
              "less than this value (m/s)");
DEFINE_bool(enable_nudge_decision, true, "enable nudge decision");
DEFINE_bool(enable_nudge_slowdown, true,
            "True to slow down when nudge obstacles.");

DEFINE_bool(try_history_decision, false, "try history decision first");

DEFINE_double(static_decision_nudge_l_buffer, 0.5, "l buffer for nudge");
DEFINE_double(lateral_ignore_buffer, 3.0,
              "If an obstacle's lateral distance is further away than this "
              "distance, ignore it");
DEFINE_double(max_stop_distance_obstacle, 10.0,
              "max stop distance from in-lane obstacle (meters)");
DEFINE_double(min_stop_distance_obstacle, 6.0,
              "min stop distance from in-lane obstacle (meters)");
DEFINE_double(nudge_distance_obstacle, 0.5,
              "minimum distance to nudge a obstacle (meters)");
DEFINE_double(follow_min_distance, 3.0,
              "min follow distance for vehicles/bicycles/moving objects");
DEFINE_double(yield_distance, 3.0,
              "min yield distance for vehicles/moving objects "
              "other than pedestrians/bicycles");
DEFINE_double(yield_distance_pedestrian_bycicle, 5.0,
              "min yield distance for pedestrians/bicycles");
DEFINE_double(
    follow_time_buffer, 2.5,
    "follow time buffer (in second) to calculate the following distance.");
DEFINE_double(
    follow_min_time_sec, 0.1,
    "min following time in st region before considering a valid follow");
DEFINE_double(within_lane_bound, 4.0,
              "distance to be considered within current lane");

DEFINE_double(virtual_stop_wall_length, 0.1,
              "virtual stop wall length (meters)");
DEFINE_double(virtual_stop_wall_height, 2.0,
              "virtual stop wall height (meters)");
DEFINE_string(reference_line_end_obstacle_id, "REF_END",
              "Obstacle id for the end of reference line obstacle");
DEFINE_double(signal_expire_time_sec, 5.0,
              "consider the signal msg is expired if its timestamp over "
              "this threshold (second)");

// Speed Decider
DEFINE_double(low_speed_obstacle_threshold, 2.0,
              "speed lower than this value is considered as low speed");
DEFINE_double(
    decelerating_obstacle_threshold, -0.25,
    "acceleration lower than this value is considered as decelerating");

// Prediction Part
DEFINE_double(prediction_total_time, 5.0, "Total prediction time");
DEFINE_bool(align_prediction_time, false,
            "enable align prediction data based planning time");

// Trajectory
DEFINE_bool(enable_rule_layer, true,
            "enable rule for trajectory before model computation");

// Traffic decision
/// common
DEFINE_double(max_stop_distance_buffer, 4.0,
              "distance buffer of passing stop line");
DEFINE_double(max_stop_speed, 0.2, "max speed(m/s) to be considered as a stop");
DEFINE_double(max_stop_deceleration, 6.0, "max deceleration");
DEFINE_double(max_valid_stop_distance, 3.0,
              "max distance(m) to the stop line to be "
              "considered as a valid stop");
DEFINE_double(creep_stop_distance, 0.5,
              "stop distance(m) to the stop line of next lane overlap "
              "while creeping ");
/// keep_clear
DEFINE_bool(enable_keep_clear, false, "enable keep clear zone");
DEFINE_string(keep_clear_virtual_object_id_prefix, "KC_",
              "prefix for converting keep_clear id to virtual object id");
DEFINE_double(keep_clear_min_pass_distance, 2.0,
              "valid min distance(m) for vehicles to be considered as "
              "have passed keep_clear zone (stop_line_end_s)");
/// traffic light
DEFINE_bool(enable_traffic_light, true, "True to enable traffic light input.");
DEFINE_string(signal_light_virtual_object_id_prefix, "SL_",
              "prefix for converting signal id to virtual object id");
DEFINE_double(max_stop_deacceleration_for_yellow_light, 3.0,
              "treat yellow light as red when deceleration (abstract value"
              " in m/s^2) is less than this threshold; otherwise treated"
              " as green light");
DEFINE_double(traffic_light_stop_distance, 1.0,
              "stop distance from traffic light line");
/// crosswalk
DEFINE_bool(enable_crosswalk, true, "enable crosswalk");
DEFINE_string(crosswalk_virtual_object_id_prefix, "CW_",
              "prefix for converting crosswalk id to virtual object id");
DEFINE_double(crosswalk_expand_distance, 2.0,
              "crosswalk expand distance(meter) "
              "for pedestrian/bicycle detection");
DEFINE_double(crosswalk_strick_l_distance, 4.0,
              "strick stop rule within this l_distance");
DEFINE_double(crosswalk_loose_l_distance, 5.0,
              "loose stop rule beyond this l_distance");
DEFINE_double(crosswalk_min_pass_distance, 1.0,
              "valid min distance(m) for vehicles to be considered as "
              "have passed crosswalk (stop_line_end_s)");
DEFINE_double(crosswalk_stop_distance, 1.0,
              "stop distance from stop line of crosswalk");
/// stop_sign
DEFINE_bool(enable_stop_sign, true, "enable stop_sign");
DEFINE_bool(enable_stop_sign_creeping, false,
            "enable stop_sign creeping forward at one way "
            "or two way stop signs.");
DEFINE_string(stop_sign_virtual_object_id_prefix, "SS_",
              "prefix for converting stop_sign id to virtual object id");
DEFINE_double(stop_sign_stop_duration, 3.0,
              "min time(second) to stop at stop sign");
DEFINE_double(stop_sign_min_pass_distance, 3.0,
              "valid min distance(m) for vehicles to be considered as "
              "have passed stop sign (stop_line_end_s)");
DEFINE_double(stop_sign_stop_distance, 1.0,
              "stop distance from stop line of stop sign");
DEFINE_double(stop_sign_max_watch_vehicle_stop_speed, 0.5,
              "max speed(m/s) for watch vehicles to be considered as a stop."
              "(this check is looser than adc)");
/// destination
DEFINE_string(destination_obstacle_id, "DEST",
              "obstacle id for converting destination to an obstacle");
DEFINE_double(destination_check_distance, 5.0,
              "if the distance between destination and ADC is less than this,"
              " it is considered to reach destination");
DEFINE_double(destination_stop_distance, 0.5,
              "stop distance from destination line");

// according to DMV's rule, turn signal should be on within 200 ft from
// intersection.
DEFINE_double(
    turn_signal_distance, 100.00,
    "In meters. If there is a turn within this distance, use turn signal");
DEFINE_bool(right_turn_creep_forward, false,
            "Creep forward at right turn when the signal is red and traffic "
            "rule is not violated.");

// planning config file
DEFINE_string(planning_config_file,
              "modules/planning/conf/planning_config.pb.txt",
              "planning config file");

DEFINE_int32(trajectory_point_num_for_debug, 10,
             "number of output trajectory points for debugging");

DEFINE_bool(enable_record_debug, true,
            "True to enable record debug into debug protobuf.");
DEFINE_bool(enable_prediction, true, "True to enable prediction input.");

DEFINE_bool(enable_lag_prediction, true,
            "Enable lagged prediction, which is more tolerant to obstacles "
            "that appear and disappear quickly");
DEFINE_int32(lag_prediction_min_appear_num, 5,
             "The minimum of appearance of the obstacle for lagged prediction");
DEFINE_double(lag_prediction_max_disappear_num, 3,
              "In lagged prediction, ignore obstacle disappeared for more "
              "than this value");
DEFINE_double(lag_prediction_protection_distance, 30,
              "Within this distance, we do not use lagged prediction");

DEFINE_double(perception_confidence_threshold, 0.4,
              "Skip the obstacle if its confidence is lower than "
              "this threshold.");

// QpSt optimizer
DEFINE_bool(enable_slowdown_profile_generator, true,
            "True to enable slowdown speed profile generator.");
DEFINE_double(slowdown_profile_deceleration, -1.0,
              "The deceleration to generate slowdown profile. unit: m/s^2.");
DEFINE_bool(enable_follow_accel_constraint, true,
            "Enable follow acceleration constraint.");

// SQP solver
DEFINE_bool(enable_sqp_solver, true, "True to enable SQP solver.");

/// thread pool
DEFINE_int32(num_thread_planning_thread_pool, 5,
             "num of thread used in planning thread pool.");
DEFINE_bool(use_multi_thread_to_add_obstacles, false,
            "use multiple thread to add obstacles.");
DEFINE_bool(
    enable_multi_thread_in_dp_poly_path, false,
    "Enable multiple thread to calculation curve cost in dp_poly_path.");
DEFINE_bool(enable_multi_thread_in_dp_st_graph, false,
            "Enable multiple thread to calculation curve cost in dp_st_graph.");

/// Lattice Planner
DEFINE_double(lattice_epsilon, 1e-6, "Epsilon in lattice planner.");
DEFINE_int32(num_lattice_traj_to_plot, 5,
             "Number of lattice trajectories to plot");
DEFINE_double(default_cruise_speed, 5.0, "default cruise speed");
DEFINE_double(spiral_downsample_curvature_thred, 0.02,
              "curvature threshold for down sampling reference line points");
DEFINE_bool(enable_sample_bound_planning, true,
            "enable SampleBound based motion planning");
DEFINE_bool(enable_lattice_st_image_dump, false,
            "enable sending the lattice st image");
DEFINE_bool(enable_auto_tuning, false, "enable auto tuning data emission");
DEFINE_double(trajectory_time_resolution, 0.1,
              "Trajectory time resolution in planning");
DEFINE_double(trajectory_space_resolution, 1.0,
              "Trajectory space resolution in planning");
DEFINE_double(collision_buffer_expansion_ratio, 0.2,
              "The ratio w.r.t. the vehicle dimension "
              "to expand in collision checking");
DEFINE_double(decision_horizon, 200.0,
              "Longitudinal horizon for decision making");
DEFINE_double(lateral_obstacle_ignore_thred, 2.0,
              "Lateral threshold for "
              "obstacles to be considered in path-time graph");
DEFINE_bool(enable_backup_trajectory, false,
            "If generate backup trajectory when planning fail");
DEFINE_double(backup_trajectory_cost, 1000.0,
              "Default cost of backup trajectory");

// Lattice Evaluate Parameters
DEFINE_double(weight_lon_travel, 6.0, "Weight of longitudinal travel cost");
DEFINE_double(weight_lon_jerk, 1.0, "Weight of longitudinal jerk cost");
DEFINE_double(weight_lon_collision, 2.0,
              "Weight of logitudinal collision cost");
DEFINE_double(weight_lat_offset, 2.0, "Weight of lateral offset cost");
DEFINE_double(weight_same_side_offset, 1.0,
              "Weight of same side lateral offset cost");
DEFINE_double(weight_opposite_side_offset, 10.0,
              "Weight of opposite side lateral offset cost");
DEFINE_double(weight_dist_travelled, 10.0, "Weight of travelled distance cost");
DEFINE_double(weight_target_speed, 1.0, "Weight of target speed cost");
DEFINE_double(lat_offset_bound, 3.0, "The bound of lateral offset");
DEFINE_double(lon_collision_yield_buffer, 1.0,
              "Longitudinal collision buffer for yield");
DEFINE_double(lon_collision_overtake_buffer, 5.0,
              "Longitudinal collision buffer for overtake");
DEFINE_double(lon_collision_cost_std, 0.5,
              "The standard deviation of logitudinal collision cost function");
