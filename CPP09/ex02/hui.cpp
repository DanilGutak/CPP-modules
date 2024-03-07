#include <iostream>
#include <vector>
#include <algorithm>

int jacobsthal(int n) {
    return round((pow(2, n) + pow(-1, n - 1)) / 3);
}

std::vector<int> pending_element_order(int n) {
    std::vector<int> order;
    int i = 0;
    while (jacobsthal(i) < n) {
        order.push_back(jacobsthal(i));
        ++i;
    }
    order.push_back(n);
    return order;
}

int binary_search_insertion_point(int n, const std::vector<int>& coll) {
    int lower_bound = 0;
    int upper_bound = coll.size() - 1;
    while (lower_bound <= upper_bound) {
        int mid_index = (lower_bound + upper_bound) / 2;
        if (n > coll[mid_index]) {
            lower_bound = mid_index + 1;
        } else if (n < coll[mid_index]) {
            upper_bound = mid_index - 1;
        } else {
            return mid_index;
        }
    }
    return lower_bound;
}

std::vector<int> insert(int n, int i, const std::vector<int>& coll) {
    std::vector<int> result(coll.begin(), coll.begin() + i);
    result.push_back(n);
    result.insert(result.end(), coll.begin() + i, coll.end());
    return result;
}

std::vector<int> binary_insert(int n, const std::vector<int>& coll) {
    int insertion_point = binary_search_insertion_point(n, coll);
    return insert(n, insertion_point, coll);
}

std::vector<int> merge_insertion_sort(const std::vector<int>& coll) {
    if (coll.size() < 2)
        return coll;

    std::vector<std::vector<int> > sorted_pairs;
    for (size_t i = 0; i < coll.size(); i += 2) {
        std::vector<int> pair(2);
        pair[0] = coll[i];
        pair[1] = (i + 1 < coll.size()) ? coll[i + 1] : coll.back();
        if (pair[1] < pair[0])
            std::swap(pair[0], pair[1]);
        sorted_pairs.push_back(pair);
    }

    std::sort(sorted_pairs.begin(), sorted_pairs.end());

    std::vector<int> main_chain;
    std::vector<int> pending_elements;
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        main_chain.push_back(sorted_pairs[i][0]);
        pending_elements.push_back(sorted_pairs[i][1]);
    }
    if (coll.size() % 2 != 0)
        pending_elements.push_back(coll.back());

    std::vector<int> a_positions(main_chain.size());
    for (size_t i = 0; i < a_positions.size(); ++i)
        a_positions[i] = i;

    std::vector<int> result;
    for (size_t i = 0; i < pending_elements.size(); ++i) {
        int n = pending_elements[i];
        int insert_index = binary_search_insertion_point(n, main_chain);
        a_positions = std::vector<int>(a_positions.begin(), a_positions.begin() + insert_index + 1);
        main_chain = insert(n, insert_index, main_chain);
    }

    return main_chain;
}

int main() {
    std::vector<int> coll;
    coll.push_back(5);
    coll.push_back(2);
    coll.push_back(6);
    coll.push_back(3);
    coll.push_back(1);
    coll.push_back(4);
    coll.push_back(4);
    coll.push_back(7);
    coll.push_back(8);
    coll.push_back(9);
    coll.push_back(10);

    std::vector<int> sorted_coll = merge_insertion_sort(coll);
    std::cout << "Sorted Array:" << std::endl;
    for (size_t i = 0; i < sorted_coll.size(); ++i) {
        std::cout << sorted_coll[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
