#pragma once

namespace mir3d
{
	template <typename K, typename V> 
    class CConcurrentMap
	{
	public:
		CConcurrentMap() = default;
		~CConcurrentMap()			{ _map.clear(); }

    public:
		void Insert(const K& key_, const V& value_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			_map.insert(std::make_pair(key_, value_));
		}


		void Upsert(const K& key_, const V& value_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			_map.erase(key_);
			_map.insert(std::make_pair(key_, value_));
		}


		V Get(const K& key_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _map.find(key_);
			if (_map.end() != iter)
			{
				return iter->second;
			}

			return nullptr;
		}

		V GetInt(const K& key_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _map.find(key_);
			if (_map.end() != iter)
			{
				return iter->second;
			}

			return 0;
		}

		bool GetErase(const K& key_, V& value_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _map.find(key_);
			if (_map.end() != iter)
			{
				value_ = iter->second;

				_map.erase(key_);

				return true;
			}

			return false;
		}

		size_t Erase(const K& key_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _map.erase(key_);
		}


		size_t Get(std::vector<V>& list)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			list.reserve(_map.size());

			auto iter = _map.begin();
			while (_map.end() != iter)
			{
				list.emplace_back(iter->second);
				++iter;
			}

			return _map.size();
		}

		size_t First(K& key_, V& value_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _map.begin();
			if (iter != _map.end())
			{
				key_ = iter->first;
				value_ = iter->second;
			}

			return _map.size();
		}

		bool Exists(const K& key_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return (0 < _map.count(key_));
		}

		size_t Size()
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _map.size();
		}


    private:
		std::unordered_map<K, V>	_map;
        std::mutex					_mutex;

	private:
		CConcurrentMap(const CConcurrentMap &) = delete;
		CConcurrentMap &operator=(const CConcurrentMap &) = delete;
		CConcurrentMap(CConcurrentMap&&) = delete;
		CConcurrentMap& operator=(CConcurrentMap&&) = delete;
	};
} // namespace mir3d
