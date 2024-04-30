#pragma once

#include <unordered_map>

namespace mir3d
{
	template <typename KeyElement>
	class CTrieMap
	{
	private:
		struct TrieNode
		{
			bool enabled = false;
			std::unordered_map<KeyElement, TrieNode> next_node_map;
		};

		TrieNode root_node;

		void InsertNode(const KeyElement* const key_vector, const std::size_t size)
		{
			decltype(root_node)* current_node = &root_node;

			for (std::size_t index = 0; index < size; index++)
				current_node = &(current_node->next_node_map[key_vector[index]]);

			current_node->enabled = true;
		}

	public:
		bool Find(const KeyElement* const key_vector, const std::size_t size)
		{
			decltype(root_node)* current_node = &root_node;

			for (std::size_t index = 0; !(current_node->enabled) && index < size; index++)
			{
				auto node_iter = current_node->next_node_map.find(key_vector[index]);

				if (node_iter == current_node->next_node_map.end())
					return false;

				current_node = &node_iter->second;
			}

			return current_node->enabled;
		}

		void Insert(const KeyElement* const key_vector, const std::size_t size)
		{
			InsertNode(key_vector, size);
		}

		void Insert(const KeyElement& key)
		{
			Insert(&key, 1);
		}

		template <typename... Args>
		void InsertWithVariadicKey(Args... key_args)
		{
			KeyElement key_vector[] = { key_args... };

			Insert(key_vector, sizeof...(Args));
		}

		bool Find(const KeyElement& key)
		{
			return Find(&key, 1);
		}

		template <typename... Args>
		bool FindWithVariadicKey(Args... key_args)
		{
			KeyElement key_vector[] = { key_args... };

			return Find(key_vector, sizeof...(Args));
		}
	};
}
