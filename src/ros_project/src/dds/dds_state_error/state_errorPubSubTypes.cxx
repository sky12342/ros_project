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
 * @file state_errorPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastddsgen.
 */


#include <fastdds/rtps/common/CdrSerialization.hpp>

#include "state_errorPubSubTypes.h"
#include "state_errorCdrAux.hpp"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;
using DataRepresentationId_t = eprosima::fastdds::dds::DataRepresentationId_t;

namespace state_and_error {


    StatePubSubType::StatePubSubType()
    {
        setName("state_and_error::State");
        uint32_t type_size =
    #if FASTCDR_VERSION_MAJOR == 1
            static_cast<uint32_t>(State::getMaxCdrSerializedSize());
    #else
            state_and_error_State_max_cdr_typesize;
    #endif
        type_size += static_cast<uint32_t>(eprosima::fastcdr::Cdr::alignment(type_size, 4)); /* possible submessage alignment */
        m_typeSize = type_size + 4; /*encapsulation*/
        m_isGetKeyDefined = false;
        uint32_t keyLength = state_and_error_State_max_key_cdr_typesize > 16 ? state_and_error_State_max_key_cdr_typesize : 16;
        m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
        memset(m_keyBuffer, 0, keyLength);
    }

    StatePubSubType::~StatePubSubType()
    {
        if (m_keyBuffer != nullptr)
        {
            free(m_keyBuffer);
        }
    }

    bool StatePubSubType::serialize(
            void* data,
            SerializedPayload_t* payload,
            DataRepresentationId_t data_representation)
    {
        State* p_type = static_cast<State*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
        payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    #if FASTCDR_VERSION_MAJOR > 1
        ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2);
    #endif // FASTCDR_VERSION_MAJOR > 1

        try
        {
            // Serialize encapsulation
            ser.serialize_encapsulation();
            // Serialize the object.
            ser << *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        // Get the serialized length
    #if FASTCDR_VERSION_MAJOR == 1
        payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    #else
        payload->length = static_cast<uint32_t>(ser.get_serialized_data_length());
    #endif // FASTCDR_VERSION_MAJOR == 1
        return true;
    }

    bool StatePubSubType::deserialize(
            SerializedPayload_t* payload,
            void* data)
    {
        try
        {
            // Convert DATA to pointer of your type
            State* p_type = static_cast<State*>(data);

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

            // Object that deserializes the data.
            eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN
    #if FASTCDR_VERSION_MAJOR == 1
                    , eprosima::fastcdr::Cdr::CdrType::DDS_CDR
    #endif // FASTCDR_VERSION_MAJOR == 1
                    );

            // Deserialize encapsulation.
            deser.read_encapsulation();
            payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            // Deserialize the object.
            deser >> *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        return true;
    }

    std::function<uint32_t()> StatePubSubType::getSerializedSizeProvider(
            void* data,
            DataRepresentationId_t data_representation)
    {
        return [data, data_representation]() -> uint32_t
               {
    #if FASTCDR_VERSION_MAJOR == 1
                   static_cast<void>(data_representation);
                   return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<State*>(data))) +
                          4u /*encapsulation*/;
    #else
                   try
                   {
                       eprosima::fastcdr::CdrSizeCalculator calculator(
                           data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                           eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
                       size_t current_alignment {0};
                       return static_cast<uint32_t>(calculator.calculate_serialized_size(
                                   *static_cast<State*>(data), current_alignment)) +
                               4u /*encapsulation*/;
                   }
                   catch (eprosima::fastcdr::exception::Exception& /*exception*/)
                   {
                       return 0;
                   }
    #endif // FASTCDR_VERSION_MAJOR == 1
               };
    }

    void* StatePubSubType::createData()
    {
        return reinterpret_cast<void*>(new State());
    }

    void StatePubSubType::deleteData(
            void* data)
    {
        delete(reinterpret_cast<State*>(data));
    }

    bool StatePubSubType::getKey(
            void* data,
            InstanceHandle_t* handle,
            bool force_md5)
    {
        if (!m_isGetKeyDefined)
        {
            return false;
        }

        State* p_type = static_cast<State*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                state_and_error_State_max_key_cdr_typesize);

        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS, eprosima::fastcdr::CdrVersion::XCDRv1);
    #if FASTCDR_VERSION_MAJOR == 1
        p_type->serializeKey(ser);
    #else
        eprosima::fastcdr::serialize_key(ser, *p_type);
    #endif // FASTCDR_VERSION_MAJOR == 1
        if (force_md5 || state_and_error_State_max_key_cdr_typesize > 16)
        {
            m_md5.init();
    #if FASTCDR_VERSION_MAJOR == 1
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
    #else
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.get_serialized_data_length()));
    #endif // FASTCDR_VERSION_MAJOR == 1
            m_md5.finalize();
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_md5.digest[i];
            }
        }
        else
        {
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_keyBuffer[i];
            }
        }
        return true;
    }



    ErrorCodePubSubType::ErrorCodePubSubType()
    {
        setName("state_and_error::ErrorCode");
        uint32_t type_size =
    #if FASTCDR_VERSION_MAJOR == 1
            static_cast<uint32_t>(ErrorCode::getMaxCdrSerializedSize());
    #else
            state_and_error_ErrorCode_max_cdr_typesize;
    #endif
        type_size += static_cast<uint32_t>(eprosima::fastcdr::Cdr::alignment(type_size, 4)); /* possible submessage alignment */
        m_typeSize = type_size + 4; /*encapsulation*/
        m_isGetKeyDefined = false;
        uint32_t keyLength = state_and_error_ErrorCode_max_key_cdr_typesize > 16 ? state_and_error_ErrorCode_max_key_cdr_typesize : 16;
        m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
        memset(m_keyBuffer, 0, keyLength);
    }

    ErrorCodePubSubType::~ErrorCodePubSubType()
    {
        if (m_keyBuffer != nullptr)
        {
            free(m_keyBuffer);
        }
    }

    bool ErrorCodePubSubType::serialize(
            void* data,
            SerializedPayload_t* payload,
            DataRepresentationId_t data_representation)
    {
        ErrorCode* p_type = static_cast<ErrorCode*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
        payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    #if FASTCDR_VERSION_MAJOR > 1
        ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2);
    #endif // FASTCDR_VERSION_MAJOR > 1

        try
        {
            // Serialize encapsulation
            ser.serialize_encapsulation();
            // Serialize the object.
            ser << *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        // Get the serialized length
    #if FASTCDR_VERSION_MAJOR == 1
        payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    #else
        payload->length = static_cast<uint32_t>(ser.get_serialized_data_length());
    #endif // FASTCDR_VERSION_MAJOR == 1
        return true;
    }

    bool ErrorCodePubSubType::deserialize(
            SerializedPayload_t* payload,
            void* data)
    {
        try
        {
            // Convert DATA to pointer of your type
            ErrorCode* p_type = static_cast<ErrorCode*>(data);

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

            // Object that deserializes the data.
            eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN
    #if FASTCDR_VERSION_MAJOR == 1
                    , eprosima::fastcdr::Cdr::CdrType::DDS_CDR
    #endif // FASTCDR_VERSION_MAJOR == 1
                    );

            // Deserialize encapsulation.
            deser.read_encapsulation();
            payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            // Deserialize the object.
            deser >> *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        return true;
    }

    std::function<uint32_t()> ErrorCodePubSubType::getSerializedSizeProvider(
            void* data,
            DataRepresentationId_t data_representation)
    {
        return [data, data_representation]() -> uint32_t
               {
    #if FASTCDR_VERSION_MAJOR == 1
                   static_cast<void>(data_representation);
                   return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ErrorCode*>(data))) +
                          4u /*encapsulation*/;
    #else
                   try
                   {
                       eprosima::fastcdr::CdrSizeCalculator calculator(
                           data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                           eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
                       size_t current_alignment {0};
                       return static_cast<uint32_t>(calculator.calculate_serialized_size(
                                   *static_cast<ErrorCode*>(data), current_alignment)) +
                               4u /*encapsulation*/;
                   }
                   catch (eprosima::fastcdr::exception::Exception& /*exception*/)
                   {
                       return 0;
                   }
    #endif // FASTCDR_VERSION_MAJOR == 1
               };
    }

    void* ErrorCodePubSubType::createData()
    {
        return reinterpret_cast<void*>(new ErrorCode());
    }

    void ErrorCodePubSubType::deleteData(
            void* data)
    {
        delete(reinterpret_cast<ErrorCode*>(data));
    }

    bool ErrorCodePubSubType::getKey(
            void* data,
            InstanceHandle_t* handle,
            bool force_md5)
    {
        if (!m_isGetKeyDefined)
        {
            return false;
        }

        ErrorCode* p_type = static_cast<ErrorCode*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                state_and_error_ErrorCode_max_key_cdr_typesize);

        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS, eprosima::fastcdr::CdrVersion::XCDRv1);
    #if FASTCDR_VERSION_MAJOR == 1
        p_type->serializeKey(ser);
    #else
        eprosima::fastcdr::serialize_key(ser, *p_type);
    #endif // FASTCDR_VERSION_MAJOR == 1
        if (force_md5 || state_and_error_ErrorCode_max_key_cdr_typesize > 16)
        {
            m_md5.init();
    #if FASTCDR_VERSION_MAJOR == 1
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
    #else
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.get_serialized_data_length()));
    #endif // FASTCDR_VERSION_MAJOR == 1
            m_md5.finalize();
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_md5.digest[i];
            }
        }
        else
        {
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_keyBuffer[i];
            }
        }
        return true;
    }



    ErrorCodeReplyPubSubType::ErrorCodeReplyPubSubType()
    {
        setName("state_and_error::ErrorCodeReply");
        uint32_t type_size =
    #if FASTCDR_VERSION_MAJOR == 1
            static_cast<uint32_t>(ErrorCodeReply::getMaxCdrSerializedSize());
    #else
            state_and_error_ErrorCodeReply_max_cdr_typesize;
    #endif
        type_size += static_cast<uint32_t>(eprosima::fastcdr::Cdr::alignment(type_size, 4)); /* possible submessage alignment */
        m_typeSize = type_size + 4; /*encapsulation*/
        m_isGetKeyDefined = false;
        uint32_t keyLength = state_and_error_ErrorCodeReply_max_key_cdr_typesize > 16 ? state_and_error_ErrorCodeReply_max_key_cdr_typesize : 16;
        m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
        memset(m_keyBuffer, 0, keyLength);
    }

    ErrorCodeReplyPubSubType::~ErrorCodeReplyPubSubType()
    {
        if (m_keyBuffer != nullptr)
        {
            free(m_keyBuffer);
        }
    }

    bool ErrorCodeReplyPubSubType::serialize(
            void* data,
            SerializedPayload_t* payload,
            DataRepresentationId_t data_representation)
    {
        ErrorCodeReply* p_type = static_cast<ErrorCodeReply*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
                data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
        payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    #if FASTCDR_VERSION_MAJOR > 1
        ser.set_encoding_flag(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR :
            eprosima::fastcdr::EncodingAlgorithmFlag::PL_CDR2);
    #endif // FASTCDR_VERSION_MAJOR > 1

        try
        {
            // Serialize encapsulation
            ser.serialize_encapsulation();
            // Serialize the object.
            ser << *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        // Get the serialized length
    #if FASTCDR_VERSION_MAJOR == 1
        payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    #else
        payload->length = static_cast<uint32_t>(ser.get_serialized_data_length());
    #endif // FASTCDR_VERSION_MAJOR == 1
        return true;
    }

    bool ErrorCodeReplyPubSubType::deserialize(
            SerializedPayload_t* payload,
            void* data)
    {
        try
        {
            // Convert DATA to pointer of your type
            ErrorCodeReply* p_type = static_cast<ErrorCodeReply*>(data);

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

            // Object that deserializes the data.
            eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN
    #if FASTCDR_VERSION_MAJOR == 1
                    , eprosima::fastcdr::Cdr::CdrType::DDS_CDR
    #endif // FASTCDR_VERSION_MAJOR == 1
                    );

            // Deserialize encapsulation.
            deser.read_encapsulation();
            payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            // Deserialize the object.
            deser >> *p_type;
        }
        catch (eprosima::fastcdr::exception::Exception& /*exception*/)
        {
            return false;
        }

        return true;
    }

    std::function<uint32_t()> ErrorCodeReplyPubSubType::getSerializedSizeProvider(
            void* data,
            DataRepresentationId_t data_representation)
    {
        return [data, data_representation]() -> uint32_t
               {
    #if FASTCDR_VERSION_MAJOR == 1
                   static_cast<void>(data_representation);
                   return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ErrorCodeReply*>(data))) +
                          4u /*encapsulation*/;
    #else
                   try
                   {
                       eprosima::fastcdr::CdrSizeCalculator calculator(
                           data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
                           eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
                       size_t current_alignment {0};
                       return static_cast<uint32_t>(calculator.calculate_serialized_size(
                                   *static_cast<ErrorCodeReply*>(data), current_alignment)) +
                               4u /*encapsulation*/;
                   }
                   catch (eprosima::fastcdr::exception::Exception& /*exception*/)
                   {
                       return 0;
                   }
    #endif // FASTCDR_VERSION_MAJOR == 1
               };
    }

    void* ErrorCodeReplyPubSubType::createData()
    {
        return reinterpret_cast<void*>(new ErrorCodeReply());
    }

    void ErrorCodeReplyPubSubType::deleteData(
            void* data)
    {
        delete(reinterpret_cast<ErrorCodeReply*>(data));
    }

    bool ErrorCodeReplyPubSubType::getKey(
            void* data,
            InstanceHandle_t* handle,
            bool force_md5)
    {
        if (!m_isGetKeyDefined)
        {
            return false;
        }

        ErrorCodeReply* p_type = static_cast<ErrorCodeReply*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                state_and_error_ErrorCodeReply_max_key_cdr_typesize);

        // Object that serializes the data.
        eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS, eprosima::fastcdr::CdrVersion::XCDRv1);
    #if FASTCDR_VERSION_MAJOR == 1
        p_type->serializeKey(ser);
    #else
        eprosima::fastcdr::serialize_key(ser, *p_type);
    #endif // FASTCDR_VERSION_MAJOR == 1
        if (force_md5 || state_and_error_ErrorCodeReply_max_key_cdr_typesize > 16)
        {
            m_md5.init();
    #if FASTCDR_VERSION_MAJOR == 1
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
    #else
            m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.get_serialized_data_length()));
    #endif // FASTCDR_VERSION_MAJOR == 1
            m_md5.finalize();
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_md5.digest[i];
            }
        }
        else
        {
            for (uint8_t i = 0; i < 16; ++i)
            {
                handle->value[i] = m_keyBuffer[i];
            }
        }
        return true;
    }





} //End of namespace state_and_error

