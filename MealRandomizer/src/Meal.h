#pragma once

class Meal
{
public:
	Meal() {}
	~Meal() {}

	void SetName(std::string name);
	std::string GetName() const;
	void SetUrl(std::string url);
	std::string GetUrl() const;
	
	void SetTag(std::string);
	void RemoveTag(std::string);
	void RemoveTag(int index);
	std::vector<std::string> GetActiveTagList() const; 
	void PrintActiveTags() const;

private:
	std::string name_;
	std::string url_;
	std::vector<std::string> active_tags_;
};
