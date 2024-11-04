#pragma once
#include "Meal.h"

class MainList {
public:
	MainList() {}
	~MainList() {}

	void ReadFile(std::string filename);
	void WriteFile(std::string filename, std::string contents) const;

	void AddTag(std::string);
	const std::vector<std::string>& GetTagList() const;
	void PrintTags() const;

	void AddItem(std::string name, std::string url);
	void AddItem(std::string name, std::string url, std::vector<std::string> tags);
	void RemoveItem(std::string name);
	void RemoveItem(int index);
	std::vector<Meal> GetItemList() const;
	void PrintItems() const;
	void PrintItems(bool url, bool tags) const;


private:
	std::vector<Meal> item_list_;
	std::vector<std::string> tags_;
};