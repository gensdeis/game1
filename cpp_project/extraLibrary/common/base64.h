#pragma once

#include <string>

// https://github.com/tkislan/base64

namespace mir3d
{
	const char BASE64_CHAR[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	class Base64
	{
	public:
		static bool Encode(const char* input, int32_t input_length, char *out, int32_t out_length)
		{
			int32_t i = 0;
			int32_t j = 0;
			char *out_begin = out;
			unsigned char a3[3];
			unsigned char a4[4];

			int32_t encoded_length = out_length;
			//int32_t encoded_length = EncodedLength(input_length);

			//if (out_length < encoded_length)
			//{
			//	return false;
			//}

			while (input_length--)
			{
				a3[i++] = *input++;
				if (i == 3)
				{
					a3_to_a4(a4, a3);

					for (i = 0; i < 4; i++)
					{
						*out++ = BASE64_CHAR[a4[i]];
					}

					i = 0;
				}
			}

			if (i)
			{
				for (j = i; j < 3; j++)
				{
					a3[j] = '\0';
				}

				a3_to_a4(a4, a3);

				for (j = 0; j < i + 1; j++)
				{
					*out++ = BASE64_CHAR[a4[j]];
				}

				while ((i++ < 3))
				{
					*out++ = '=';
				}
			}

			return (out == (out_begin + encoded_length));
		}

		static bool Encode(const std::string& in, std::string* out)
		{
			int32_t i = 0, j = 0;
			int32_t enc_len = 0;
			unsigned char a3[3];
			unsigned char a4[4];

			out->resize(EncodedLength(in));

			int32_t input_len = static_cast<int32_t>(in.size());
			std::string::const_iterator input = in.begin();

			while (input_len--)
			{
				a3[i++] = *(input++);
				if (i == 3)
				{
					a3_to_a4(a4, a3);

					for (i = 0; i < 4; i++)
					{
						(*out)[enc_len++] = BASE64_CHAR[a4[i]];
					}

					i = 0;
				}
			}

			if (i)
			{
				for (j = i; j < 3; j++)
				{
					a3[j] = '\0';
				}

				a3_to_a4(a4, a3);

				for (j = 0; j < i + 1; j++)
				{
					(*out)[enc_len++] = BASE64_CHAR[a4[j]];
				}

				while ((i++ < 3))
				{
					(*out)[enc_len++] = '=';
				}
			}

			return (enc_len == (int32_t)out->size());
		}

		static bool Decode(const std::string &in, std::string *out)
		{
			int32_t i = 0;
			int32_t j = 0;
			int32_t dec_len = 0;
			unsigned char a3[3];
			unsigned char a4[4];

			int32_t input_len = static_cast<int32_t>(in.size());
			std::string::const_iterator input = in.begin();

			out->resize(DecodedLength(in));

			while (input_len--)
			{
				if (*input == '=')
				{
					break;
				}

				a4[i++] = *(input++);
				if (i == 4)
				{
					for (i = 0; i < 4; i++)
					{
						a4[i] = b64_lookup(a4[i]);
					}

					a4_to_a3(a3, a4);

					for (i = 0; i < 3; i++)
					{
						(*out)[dec_len++] = a3[i];
					}

					i = 0;
				}
			}

			if (i)
			{
				for (j = i; j < 4; j++)
				{
					a4[j] = '\0';
				}

				for (j = 0; j < 4; j++)
				{
					a4[j] = b64_lookup(a4[j]);
				}

				a4_to_a3(a3, a4);

				for (j = 0; j < i - 1; j++)
				{
					(*out)[dec_len++] = a3[j];
				}
			}

			return (dec_len == (int32_t)out->size());
		}
				
		static bool Decode(const char* input, int32_t input_length, char* out, int32_t out_length)
		{
			int32_t i = 0;
			int32_t j = 0;
			char *out_begin = out;
			unsigned char a3[3];
			unsigned char a4[4];

			int32_t decoded_length = out_length;
			//int32_t decoded_length = DecodedLength(input, input_length);

			//if (out_length < decoded_length) return false;

			while (input_length--)
			{
				if (*input == '=')
				{
					break;
				}

				a4[i++] = *(input++);
				if (i == 4)
				{
					for (i = 0; i < 4; i++)
					{
						a4[i] = b64_lookup(a4[i]);
					}

					a4_to_a3(a3, a4);

					for (i = 0; i < 3; i++)
					{
						*out++ = a3[i];
					}

					i = 0;
				}
			}

			if (i)
			{
				for (j = i; j < 4; j++)
				{
					a4[j] = '\0';
				}

				for (j = 0; j < 4; j++)
				{
					a4[j] = b64_lookup(a4[j]);
				}

				a4_to_a3(a3, a4);

				for (j = 0; j < i - 1; j++)
				{
					*out++ = a3[j];
				}
			}

			return (out == (out_begin + decoded_length));
		}

		static inline int32_t EncodedLength(const std::string &in)
		{
			return EncodedLength(static_cast<int32_t>(in.length()));
		}

		static inline int32_t EncodedLength(int32_t length)
		{
			return (length + 2 - ((length + 2) % 3)) / 3 * 4;
		}

		static int32_t DecodedLength(const std::string &in)
		{
			int32_t numEq = 0;
			int32_t n = static_cast<int32_t>(in.size());

			for (std::string::const_reverse_iterator it = in.rbegin(); *it == '='; ++it)
			{
				++numEq;
			}

			return ((6 * n) / 8) - numEq;
		}

		static int32_t DecodedLength(const char* in, int32_t in_length)
		{
			int32_t numEq = 0;

			const char *in_end = in + in_length;
			while (*--in_end == '=') ++numEq;

			return ((6 * in_length) / 8) - numEq;
		}

	private:		
		static inline void StripPadding(std::string *in)
		{
			while (!in->empty() && *(in->rbegin()) == '=') in->resize(in->size() - 1);
		}
	private:
		static inline void a3_to_a4(unsigned char * a4, unsigned char * a3)
		{
			a4[0] = (a3[0] & 0xfc) >> 2;
			a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xf0) >> 4);
			a4[2] = ((a3[1] & 0x0f) << 2) + ((a3[2] & 0xc0) >> 6);
			a4[3] = (a3[2] & 0x3f);
		}

		static inline void a4_to_a3(unsigned char * a3, unsigned char * a4)
		{
			a3[0] = (a4[0] << 2) + ((a4[1] & 0x30) >> 4);
			a3[1] = ((a4[1] & 0xf) << 4) + ((a4[2] & 0x3c) >> 2);
			a3[2] = ((a4[2] & 0x3) << 6) + a4[3];
		}

		static inline unsigned char b64_lookup(unsigned char c)
		{
			if (c >= 'A' && c <= 'Z') return c - 'A';
			if (c >= 'a' && c <= 'z') return c - 71;
			if (c >= '0' && c <= '9') return c + 4;
			if (c == '+') return 62;
			if (c == '/') return 63;
			return 255;
		}
	};
}