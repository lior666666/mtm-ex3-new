template <typename T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    size_t size = vec.size();
    if (start < 0 || start >= size || stop < 0 || stop > size || step <= 0)
    {
        throw BadInput();
    }
    std::vector<T> sliced_vector;
    if (start >= stop)
    {
        return sliced_vector;
    }
    for (int i = start; i < stop; i += step)
    {
        sliced_vector.push_back(vec.at(i));
    }
    return sliced_vector;
}

class A {
    public:
        std::vector<std::shared_ptr<int>> values;
        void add(int x)
        {
            std::shared_ptr<int> ptr(new int(x));
            values.push_back(ptr);
        }
};