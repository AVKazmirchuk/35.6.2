#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v{ 1, 2, 2, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9 };

    int countRepit{};

    auto l{ [&countRepit](std::vector<int>& v)
    {
        std::unordered_set<int> us;

        for (const auto& elem : v)
        {
            if (!us.insert(elem).second) ++countRepit;
        }
        
        auto u_ptr = std::make_unique<std::vector<int>>(us.size());

        std::copy(us.cbegin(), us.cend(), u_ptr.get()->begin());

        return u_ptr;
    } };

    std::cout << "v: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    
    auto u_ptr = l(v);

    std::cout << "\nNumber of repetitions: " << countRepit;

    std::cout << "\nv2: ";
    std::copy(u_ptr.get()->cbegin(), u_ptr.get()->cend(), std::ostream_iterator<int>(std::cout, " "));
}