#pragma once
#ifndef SIMPLE_NMATRIX
#define SIMPLE_NMATRIX

#include<type_traits>
#include<stdexcept>
#include<vector>
#include<array>
#include<memory>

namespace my
{
	using Index = int;

	template<Index NDim, class T, class A = std::allocator<T>, typename = std::enable_if_t<(NDim > 1)>>
	class simple_nmatrix
	{
	public:
		explicit simple_nmatrix(const std::array<Index, NDim>& dimentions, const T& val = T(), const A& alloc = A())
			: values{ compute_size(dimentions), alloc }, dim_sizes{ dimentions } {}

		const std::array<Index, NDim>& dimentions(){ return dim_sizes; }

		T& at(const std::array<Index, NDim>& indexes) { return values.at(compute_index(indexes)); }

		virtual ~simple_nmatrix() {}

	protected:
		Index compute_index(const std::array<Index, NDim>& indexes)
		{
			Index result = 1;
			for (Index i = 0; i < NDim - 1; ++i)
			{
				if (indexes[i] < 0 || indexes[i] >= dim_sizes[i])
					throw std::out_of_range{ "one of indexes is out of range" };

				result *= indexes[i];
			}

			return result += indexes.back();
		}

		Index compute_size(const std::array<Index, NDim>& indexes)
		{
			Index result = 1;
			for (Index i = 0; i < NDim; ++i)
			{
				if (indexes[i] < 0 || indexes[i] > dim_sizes[i])
					throw std::invalid_argument{ "invalid indexes" };

				result *= indexes[i];
			}
			return result;
		}

		std::array<Index, NDim> dim_sizes;
		std::vector<T, A> values;
	};
}

#endif // !SIMPLE_NMATRIX
