#pragma once

class IView
{
public:
	virtual void render() const = 0;
	virtual ~IView() {};
};