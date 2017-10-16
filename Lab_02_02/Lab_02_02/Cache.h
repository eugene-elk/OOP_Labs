#pragma once

class Cache {
public:

	mutable bool changeAfterGetAvg;
	mutable bool changeAfterGetCountUnder;
	mutable bool changeAfterGetCountAbove;
	mutable float lastGetAvg;
	mutable int lastGetCountUnder;
	mutable int lastGetCountAbove;

	Cache();
	~Cache() = default;

	void change();
};
