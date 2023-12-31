//
// Created by lx on 2023/5/17.
//

#ifndef ACM_DBG_HPP
#define ACM_DBG_HPP


#include <bits/stdc++.h>
using namespace std;


template <typename T>
constexpr bool is_tuple = false;

template<typename ... types>
constexpr bool is_tuple<tuple<types...>> = true;

template<typename A, typename B>
constexpr bool is_tuple<pair<A, B>> = true;


template<typename T> struct IsContainer {
    typedef typename remove_const<T>::type test_type;
    template<typename A> static constexpr bool test(A* pt, decltype(pt->begin())* = nullptr, decltype(pt->end())* = nullptr)
    { return is_same<decltype(pt->begin()),typename A::iterator>::value && is_same<decltype(pt->end()),typename A::iterator>::value; }
    template<typename A> static constexpr bool test(...) { return false; }
    static constexpr bool value = test<test_type>(nullptr);
};

template<typename T>
constexpr bool is_container = IsContainer<T>::value;


template <typename T>
constexpr bool is_string = is_same<T, string>::value;

template<typename>
struct to_mutable { };

template<typename... Ts>
struct to_mutable<tuple<Ts...>> {
    using type = tuple<typename remove_cv<Ts>::type...>;
};

template<typename... Ts>
struct to_mutable<pair<Ts...>> {
    using type = pair<typename remove_cv<Ts>::type...>;
};


string readline() { string value; getline(cin, value); return value; }

template<typename T, typename ...Args> typename enable_if<!is_tuple<T> && (!is_container<T> || is_string<T>), T>::type read() {
    T value;
    cin >> value;
    return value;
}

template<typename T, typename ...Args> typename enable_if<is_tuple<T>, T>::type read(Args ...args);
template<typename T, typename ...Args> typename enable_if<is_container<T>, T>::type read(size_t N, Args... args);

template<typename T> typename enable_if<is_container<T> && !is_string<T>, T>::type read() {
    size_t N = read<size_t>();
    return read<T>(N);
}

template<typename X, size_t I = 0, typename ...Args, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, typename to_mutable<X>::type>::type read_tuple(Args... args) { return typename to_mutable<X>::type(); }

template<typename X, size_t I = 0, typename ...Args, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, typename to_mutable<X>::type>::type read_tuple(Args... args) {
    auto tmp = read<typename tuple_element<I, typename to_mutable<X>::type>::type>(args...);
    typename to_mutable<X>::type value = read_tuple<X, I + 1>(args...);
    get<I>(value) = tmp;
    return value;
}

template<typename T, typename ...Args> typename enable_if<is_tuple<T>, T>::type read(Args... args) { return read_tuple<T>(args...); }

template<typename T, typename ...Args> typename enable_if<is_container<T>, T>::type read(size_t N, Args... args) {
    T container;
    for(size_t i = 0;i < N;i++) {
        *inserter(container, container.end()) = read<typename T::value_type>(args...);
    }
    return container;
}


void flush() { cout << flush; }
void writesp() { cout << " "; }
void writeln() { cout << "\n"; }

template<typename T> void writesp(const T& value);
template<typename T> void writeln(const T& value);

template<typename T, typename enable_if<!is_container<T> && !is_tuple<T>, T>::type* = nullptr>
void write(const T& value) { cout << value; }
void write(const string& value) { cout << value; }
void write(const char* value) { cout << value; }

template<typename T, typename enable_if<is_container<T>, T>::type* = nullptr> void writerow(const T& value) {
    typedef typename T::const_iterator It;
    for(It it = value.begin();it != value.end();it++) { writesp(*it); }
}

template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, void>::type writerow(const X& t) {}
template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, void>::type writerow(const X& t) { writesp(get<I>(t)); writerow<I + 1>(t); }

template<typename T, typename enable_if<is_container<T>, T>::type* = nullptr> void writecol(const T& value) {
    typedef typename T::const_iterator It;
    for(It it = value.begin();it != value.end();it++) { writeln(*it); }
}

template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I == tuple_size<X>::value, void>::type writecol(const X& t) {}
template<size_t I = 0, typename X, typename enable_if<is_tuple<X>, X>::type* = nullptr>
typename enable_if<I < tuple_size<X>::value, void>::type writecol(const X& t) { writesp(get<I>(t)); writerow<I + 1>(t); }

template<typename T, typename enable_if<!is_container<typename T::value_type> && !is_tuple<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { writerow(value); }
template<typename T, typename enable_if<is_tuple<T>, T>::type* = nullptr> void write(const T& value) { writerow(value); }

template<typename T> void write2d(const T& value) {
    typedef typename T::const_iterator It;
    for(It it = value.begin();it != value.end();it++) { writeln(*it); }
}

template<typename T, typename enable_if<is_container<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { write2d(value); }
template<typename T, typename enable_if<is_tuple<typename T::value_type>, T>::type* = nullptr> void write(const T& value) { write2d(value); }

template<typename T> void writesp(const T& value) { write(value); writesp(); }
template<typename T> void writeln(const T& value) { write(value); writeln(); }


// 张晴川
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template<typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename A> string to_string(A v) { bool first = true; string res = "{"; for(auto& x : v) { if(!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#endif //ACM_DBG_HPP