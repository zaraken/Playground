#pragma once

template <class... Ts> 
class TieN2 {
protected:
	template <typename Tup, int N>
	void getN(Tup const & tup) {}
};

template <class T, class... Trest>
class TieN2<T, Trest...> : TieN2<Trest...> {
public:
	TieN2(T& t, Trest&... ts) : TieN2<Trest...>(ts...), element(t) {}

	template <typename Tup>
	Tup const & operator=(Tup const & tup) {
		getN<Tup, 0>(tup);
		return tup;
	}

protected:
	template <typename Tup, int N>
	void getN(Tup const & tup) {
		element = std::get<N>(tup);
		this->TieN2<Trest...>::getN<Tup, N + 1>(tup);
	}

private:
	T& element;
};

template<class... Ts>
TieN2<Ts...> tieN2(Ts&... args) {
	return TieN2<Ts...>(args...);
}
