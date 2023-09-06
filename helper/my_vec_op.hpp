#ifndef __MY__VEC__OP
#define __MY__VEC__OP

namespace my_vec_op {
  template <class T>
	double sum(const std::vector<T> &v) {
		double ans = 0;
		for(int i=0; i<v.size(); i++) ans += v[i].mental;
		return ans;
	}
}

#endif