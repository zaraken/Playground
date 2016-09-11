template<class... Ts>
class TieN1 {
public:
	template<class Tup, int N>
	void getN(Tup const & rhs) {}
};

template <class T, class... Trest>
class TieN1 <T, Trest...> {
public:
	TieN1(T &first, Trest&... trest) :element(first), rest(trest...) {}

	template<class Tup>
	Tup const & operator=(Tup const & rhs) {
		getN<Tup, 0>(rhs);
		return rhs;
	}

	template<class Tup, int N>
	void getN(Tup const & rhs) {
		//if (std::tuple_size<Tup>::value == N) return;
		element = std::get<N>(rhs);
		rest.getN<Tup, N + 1>(rhs);
	}

private:
	T & element;
	TieN1<Trest...> rest;
};

template<class... Ts>
TieN1<Ts...> tieN1(Ts&... args) {
	return TieN1<Ts...>(args...);
}
