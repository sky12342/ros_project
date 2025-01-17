// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file state_error.cpp
 * This source file contains the implementation of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "state_error.h"

#include <fastcdr/Cdr.h>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


namespace state_and_error {



State::State()
{
}

State::~State()
{
}

State::State(
        const State& x)
{
    m_status = x.m_status;
    m_current_x = x.m_current_x;
    m_current_y = x.m_current_y;
    m_current_theta = x.m_current_theta;
    m_linear_velocity = x.m_linear_velocity;
    m_angular_velocity = x.m_angular_velocity;
    m_feedback_message = x.m_feedback_message;
}

State::State(
        State&& x) noexcept
{
    m_status = x.m_status;
    m_current_x = x.m_current_x;
    m_current_y = x.m_current_y;
    m_current_theta = x.m_current_theta;
    m_linear_velocity = x.m_linear_velocity;
    m_angular_velocity = x.m_angular_velocity;
    m_feedback_message = std::move(x.m_feedback_message);
}

State& State::operator =(
        const State& x)
{

    m_status = x.m_status;
    m_current_x = x.m_current_x;
    m_current_y = x.m_current_y;
    m_current_theta = x.m_current_theta;
    m_linear_velocity = x.m_linear_velocity;
    m_angular_velocity = x.m_angular_velocity;
    m_feedback_message = x.m_feedback_message;
    return *this;
}

State& State::operator =(
        State&& x) noexcept
{

    m_status = x.m_status;
    m_current_x = x.m_current_x;
    m_current_y = x.m_current_y;
    m_current_theta = x.m_current_theta;
    m_linear_velocity = x.m_linear_velocity;
    m_angular_velocity = x.m_angular_velocity;
    m_feedback_message = std::move(x.m_feedback_message);
    return *this;
}

bool State::operator ==(
        const State& x) const
{
    return (m_status == x.m_status &&
           m_current_x == x.m_current_x &&
           m_current_y == x.m_current_y &&
           m_current_theta == x.m_current_theta &&
           m_linear_velocity == x.m_linear_velocity &&
           m_angular_velocity == x.m_angular_velocity &&
           m_feedback_message == x.m_feedback_message);
}

bool State::operator !=(
        const State& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function sets a value in member status
 * @param _status New value for member status
 */
void State::status(
        int32_t _status)
{
    m_status = _status;
}

/*!
 * @brief This function returns the value of member status
 * @return Value of member status
 */
int32_t State::status() const
{
    return m_status;
}

/*!
 * @brief This function returns a reference to member status
 * @return Reference to member status
 */
int32_t& State::status()
{
    return m_status;
}


/*!
 * @brief This function sets a value in member current_x
 * @param _current_x New value for member current_x
 */
void State::current_x(
        double _current_x)
{
    m_current_x = _current_x;
}

/*!
 * @brief This function returns the value of member current_x
 * @return Value of member current_x
 */
double State::current_x() const
{
    return m_current_x;
}

/*!
 * @brief This function returns a reference to member current_x
 * @return Reference to member current_x
 */
double& State::current_x()
{
    return m_current_x;
}


/*!
 * @brief This function sets a value in member current_y
 * @param _current_y New value for member current_y
 */
void State::current_y(
        double _current_y)
{
    m_current_y = _current_y;
}

/*!
 * @brief This function returns the value of member current_y
 * @return Value of member current_y
 */
double State::current_y() const
{
    return m_current_y;
}

/*!
 * @brief This function returns a reference to member current_y
 * @return Reference to member current_y
 */
double& State::current_y()
{
    return m_current_y;
}


/*!
 * @brief This function sets a value in member current_theta
 * @param _current_theta New value for member current_theta
 */
void State::current_theta(
        double _current_theta)
{
    m_current_theta = _current_theta;
}

/*!
 * @brief This function returns the value of member current_theta
 * @return Value of member current_theta
 */
double State::current_theta() const
{
    return m_current_theta;
}

/*!
 * @brief This function returns a reference to member current_theta
 * @return Reference to member current_theta
 */
double& State::current_theta()
{
    return m_current_theta;
}


/*!
 * @brief This function sets a value in member linear_velocity
 * @param _linear_velocity New value for member linear_velocity
 */
void State::linear_velocity(
        double _linear_velocity)
{
    m_linear_velocity = _linear_velocity;
}

/*!
 * @brief This function returns the value of member linear_velocity
 * @return Value of member linear_velocity
 */
double State::linear_velocity() const
{
    return m_linear_velocity;
}

/*!
 * @brief This function returns a reference to member linear_velocity
 * @return Reference to member linear_velocity
 */
double& State::linear_velocity()
{
    return m_linear_velocity;
}


/*!
 * @brief This function sets a value in member angular_velocity
 * @param _angular_velocity New value for member angular_velocity
 */
void State::angular_velocity(
        double _angular_velocity)
{
    m_angular_velocity = _angular_velocity;
}

/*!
 * @brief This function returns the value of member angular_velocity
 * @return Value of member angular_velocity
 */
double State::angular_velocity() const
{
    return m_angular_velocity;
}

/*!
 * @brief This function returns a reference to member angular_velocity
 * @return Reference to member angular_velocity
 */
double& State::angular_velocity()
{
    return m_angular_velocity;
}


/*!
 * @brief This function copies the value in member feedback_message
 * @param _feedback_message New value to be copied in member feedback_message
 */
void State::feedback_message(
        const std::string& _feedback_message)
{
    m_feedback_message = _feedback_message;
}

/*!
 * @brief This function moves the value in member feedback_message
 * @param _feedback_message New value to be moved in member feedback_message
 */
void State::feedback_message(
        std::string&& _feedback_message)
{
    m_feedback_message = std::move(_feedback_message);
}

/*!
 * @brief This function returns a constant reference to member feedback_message
 * @return Constant reference to member feedback_message
 */
const std::string& State::feedback_message() const
{
    return m_feedback_message;
}

/*!
 * @brief This function returns a reference to member feedback_message
 * @return Reference to member feedback_message
 */
std::string& State::feedback_message()
{
    return m_feedback_message;
}




ErrorCode::ErrorCode()
{
}

ErrorCode::~ErrorCode()
{
}

ErrorCode::ErrorCode(
        const ErrorCode& x)
{
    m_code = x.m_code;
}

ErrorCode::ErrorCode(
        ErrorCode&& x) noexcept
{
    m_code = std::move(x.m_code);
}

ErrorCode& ErrorCode::operator =(
        const ErrorCode& x)
{

    m_code = x.m_code;
    return *this;
}

ErrorCode& ErrorCode::operator =(
        ErrorCode&& x) noexcept
{

    m_code = std::move(x.m_code);
    return *this;
}

bool ErrorCode::operator ==(
        const ErrorCode& x) const
{
    return (m_code == x.m_code);
}

bool ErrorCode::operator !=(
        const ErrorCode& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function copies the value in member code
 * @param _code New value to be copied in member code
 */
void ErrorCode::code(
        const std::string& _code)
{
    m_code = _code;
}

/*!
 * @brief This function moves the value in member code
 * @param _code New value to be moved in member code
 */
void ErrorCode::code(
        std::string&& _code)
{
    m_code = std::move(_code);
}

/*!
 * @brief This function returns a constant reference to member code
 * @return Constant reference to member code
 */
const std::string& ErrorCode::code() const
{
    return m_code;
}

/*!
 * @brief This function returns a reference to member code
 * @return Reference to member code
 */
std::string& ErrorCode::code()
{
    return m_code;
}




ErrorCodeReply::ErrorCodeReply()
{
}

ErrorCodeReply::~ErrorCodeReply()
{
}

ErrorCodeReply::ErrorCodeReply(
        const ErrorCodeReply& x)
{
    m_description = x.m_description;
    m_suggestion = x.m_suggestion;
}

ErrorCodeReply::ErrorCodeReply(
        ErrorCodeReply&& x) noexcept
{
    m_description = std::move(x.m_description);
    m_suggestion = std::move(x.m_suggestion);
}

ErrorCodeReply& ErrorCodeReply::operator =(
        const ErrorCodeReply& x)
{

    m_description = x.m_description;
    m_suggestion = x.m_suggestion;
    return *this;
}

ErrorCodeReply& ErrorCodeReply::operator =(
        ErrorCodeReply&& x) noexcept
{

    m_description = std::move(x.m_description);
    m_suggestion = std::move(x.m_suggestion);
    return *this;
}

bool ErrorCodeReply::operator ==(
        const ErrorCodeReply& x) const
{
    return (m_description == x.m_description &&
           m_suggestion == x.m_suggestion);
}

bool ErrorCodeReply::operator !=(
        const ErrorCodeReply& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function copies the value in member description
 * @param _description New value to be copied in member description
 */
void ErrorCodeReply::description(
        const std::string& _description)
{
    m_description = _description;
}

/*!
 * @brief This function moves the value in member description
 * @param _description New value to be moved in member description
 */
void ErrorCodeReply::description(
        std::string&& _description)
{
    m_description = std::move(_description);
}

/*!
 * @brief This function returns a constant reference to member description
 * @return Constant reference to member description
 */
const std::string& ErrorCodeReply::description() const
{
    return m_description;
}

/*!
 * @brief This function returns a reference to member description
 * @return Reference to member description
 */
std::string& ErrorCodeReply::description()
{
    return m_description;
}


/*!
 * @brief This function copies the value in member suggestion
 * @param _suggestion New value to be copied in member suggestion
 */
void ErrorCodeReply::suggestion(
        const std::string& _suggestion)
{
    m_suggestion = _suggestion;
}

/*!
 * @brief This function moves the value in member suggestion
 * @param _suggestion New value to be moved in member suggestion
 */
void ErrorCodeReply::suggestion(
        std::string&& _suggestion)
{
    m_suggestion = std::move(_suggestion);
}

/*!
 * @brief This function returns a constant reference to member suggestion
 * @return Constant reference to member suggestion
 */
const std::string& ErrorCodeReply::suggestion() const
{
    return m_suggestion;
}

/*!
 * @brief This function returns a reference to member suggestion
 * @return Reference to member suggestion
 */
std::string& ErrorCodeReply::suggestion()
{
    return m_suggestion;
}







} // namespace state_and_error
// Include auxiliary functions like for serializing/deserializing.
#include "state_errorCdrAux.ipp"

