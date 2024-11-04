#include "pch.h"
#include "Meal.h"

void Meal::SetName(std::string name) {
	this->name_ = name;
}

std::string Meal::GetName() const {
	return this->name_;
}

void Meal::SetUrl(std::string url) {
	this->url_ = url;
}

std::string Meal::GetUrl() const {
	return this->url_;
}

void Meal::SetTag(std::string tag) {
	if (std::count(this->active_tags_.begin(), this->active_tags_.end(), tag) < 1) {
		this->active_tags_.push_back(tag);
	}
	else throw std::runtime_error("Tag already active");
}

void Meal::RemoveTag(std::string tag) {
	this->active_tags_.erase(std::remove(this->active_tags_.begin(), this->active_tags_.end(), tag), this->active_tags_.end());
}

void Meal::RemoveTag(int index) {
	this->active_tags_.erase(this->active_tags_.begin() + index);
}

std::vector<std::string> Meal::GetActiveTagList() const {
	return this->active_tags_;
}

void Meal::PrintActiveTags() const {
	for (int i = 0; i < this->active_tags_.size(); i++) {
		std::cout << i << ": " << this->active_tags_[i] << std::endl;
	}
}
