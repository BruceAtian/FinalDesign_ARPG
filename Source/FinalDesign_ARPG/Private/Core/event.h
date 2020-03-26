#pragma once

#include <list>
#include <functional>
#include <algorithm>
namespace core
{
	template<typename _Fty>
	class event final
	{
		enum flags
		{
			none = 0,
			expired = 0x0001,
		};
		struct callback
		{
			std::function<_Fty> function;
			int32 flag = flags::none;
			int64 uid = 0u;
			bool disposable = false;
		};

	public:
		template<typename IDType>
		void bind(std::function<_Fty> func, IDType id)
		{
			callback c;
			c.function = std::move(func);
			c.uid = id;
			_functions.push_back(std::move(c));
		}

		template<typename IDType>
		void bind_disposable(std::function<_Fty> func, IDType id)
		{
			callback c;
			c.function = std::move(func);
			c.uid = id;
			_functions.push_back(std::move(c));
			c.disposable = true;
		}

		template<typename IDType>
		void unbind(IDType id)
		{
			for (auto & c : _functions)
			{
				if (c.id == id)
				{
					c.flag |= flags.expired;
				}
			}
		}

		void operator += (std::function<_Fty> func)
		{
			bind(std::move(func), 0);
		}

		template<typename ...ArgsT>
		void operator ()(const ArgsT &... args)
		{
			for (callback& c : _functions)
			{
				if (c.flag & flags::expired)
					continue;

				if (c.function)
					c.function(args...);

				if (c.disposable)
					c.flag |= flags::expired;
			}
			_functions.erase(std::remove_if(_functions.begin(), _functions.end(), [](const callback& c) {
				return !!(c.flag & flags::expired);
			}), _functions.end());
		}

		void unbindall()
		{
			_functions.clear();
		}
	private:
		std::list<callback> _functions;
	};
}


