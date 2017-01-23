namespace efik {
    template<class T, class Key>
    T * find(const T * p_begin, const T * p_end, const Key & k)
    {
        auto ptr = p_begin;
        for (; ptr != p_end; ptr++) {
            if (*ptr == k) {
                // we shouldn't need it with matching return types
                return const_cast<T*>(ptr);
            }
        }
        return  NULL;
    }

}

