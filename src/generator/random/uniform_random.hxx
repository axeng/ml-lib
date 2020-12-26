/**
 ** @file generator/random/uniform_random.hxx
 ** @brief Inline methods of ml::generator::random::UniformRandom
 */

namespace ml::generator::random
{
    template <typename T>
    UniformRandom<T>::UniformRandom(T minimum, T maximum)
        : random_engine_(std::random_device()())
        , distribution_(minimum, maximum)
    {}

    template <typename T>
    T UniformRandom<T>::operator()()
    {
        return this->distribution_(this->random_engine_);
    }
} // namespace ml::generator::random