class Server {
	// .... (생략) ....

	// Cache cache;
	mutable Cache cache;

	// 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
	User GetUserInfo(const int user_id) const {
		// 1. 캐쉬에서 user_id 를 검색
		Data user_data = cache.find(user_id);

		// 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
		if (!user_data) {
			user_data = Database.find(user_id);

			// 그 후 캐쉬에 user_data 등록
			cache.update(user_id, user_data); // <-- 불가능, mutable 사용하여 업데이트
		}
		

		// 3. 리턴된 정보로 User 객체 생성
		return User(user_data);
	}
};