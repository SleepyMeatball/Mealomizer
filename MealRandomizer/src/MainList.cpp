#include "pch.h"
#include "MainList.h"

void MainList::ReadFile(std::string filename) {
	std::string line;
	if (!filename.ends_with(".txt")) filename += ".txt";
	std::ifstream file(filename);
	if (file.is_open()) {
		int line_count = 0;
		int bad_line_count = 0;
		while (std::getline(file, line)) {
			std::istringstream stream(line);
			std::string word, name, url;
			std::vector<std::string> tags;
			int i = 0;
			while (stream >> word) {
				if (i < 1) {
					name = word;
					i++;
				}
				else if (i == 1) {
					url = word;
					i++;
				}
				else {
					tags.push_back(word);
					i++;
				}
			}
			if (i < 1) bad_line_count++;
			else {
				if (!tags.empty()) AddItem(name, url, tags);
				else AddItem(name, url);
			}
			line_count++;
		}
		std::cout << "Total Lines: " << line_count << std::endl;
		std::cout << "Bad Lines: " << bad_line_count << std::endl;
		file.close();
	}
	else throw std::runtime_error("Could't find the specified text file");
}

void MainList::WriteFile(std::string filename, std::string contents) const {
	if (!filename.ends_with(".txt")) filename += ".txt";
	std::ofstream file(filename, std::ios::out | (std::filesystem::exists(filename) ? std::ios::app : 0));
	if (file.is_open()) {
		const std::vector<Meal>& list = this->item_list_;
		for (Meal item : list) {
			std::string name = item.GetName(), 
						url = item.GetUrl();
			std::vector<std::string> tags = item.GetActiveTagList();
			if (file << name << " " && file << url << " ") {
				int i = 1;
				for (std::string tag : tags) {
					file << tag << (i < tags.size() ? " " : "");
					i++;
				}
				file << std::endl;
			}
		}
		std::cout << "Written on " << filename << " successfully!" << std::endl;
		file.close();
	} else throw std::runtime_error("Never gonna give you up\nNever gonna let you down");
}

void MainList::AddTag(std::string tag) {
	if (this->tags_.end() != std::find(this->tags_.begin(), this->tags_.end(), tag))
		this->tags_.push_back(tag);
}

const std::vector<std::string>& MainList::GetTagList() const {
	return this->tags_;
}

void MainList::PrintTags() const {
	for (int i = 0; i < this->tags_.size(); i++) {
		std::cout << i + 1 << ": " << this->tags_.at(i) << std::endl;
	}
}

void MainList::AddItem(std::string name, std::string url) {
	for (Meal item : this->item_list_) {
		if (item.GetName() == name) return;
		if (item.GetUrl() == url) return;
	}
	Meal item;
	item.SetName(name);
	item.SetUrl(url);
	this->item_list_.push_back(item);
}

void MainList::AddItem(std::string name, std::string url, std::vector<std::string> tags) {
	for (Meal item : this->item_list_) {
		if (item.GetName() == name) return;
		if (item.GetUrl() == url) return;
	}
	Meal item;
	item.SetName(name);
	item.SetUrl(url);
	for (std::string tag : tags) {
		item.SetTag(tag);
		this->AddTag(tag);
	}
	this->item_list_.push_back(item);
}

void MainList::RemoveItem(std::string name) {
	std::vector<Meal>::iterator i = std::find_if(this->item_list_.begin(), this->item_list_.end(), [&](const Meal& item) {return item.GetName() == name;});
	if (this->item_list_.end() != i) this->item_list_.erase(i);
}

void MainList::RemoveItem(int index) {
	if (this->item_list_.size() > index) 
		this->item_list_.erase(this->item_list_.begin() + index);
}

std::vector<Meal> MainList::GetItemList() const {
	return this->item_list_;
}

void MainList::PrintItems() const {
	if (this->item_list_.empty()) {
		for (int i = 0; i < this->item_list_.size(); i++) {
			std::cout << i + 1 << ": " << this->item_list_.at(i).GetName() << std::endl;
		}
	} else {
		std::cout << "There are no elements in the list" << std::endl;
	}
}

void MainList::PrintItems(bool url, bool tags) const {
	if (this->item_list_.empty()) {
		for (int i = 0; i < this->item_list_.size(); i++) {
			const Meal& item = this->item_list_.at(i);
			std::cout << i + 1 << ": " << item.GetName() << " ";
			if (url) std::cout << "| " << item.GetUrl() << " ";
			if (tags) {
				std::cout << "[";
				int j = 0;
				for (std::string& tag : item.GetActiveTagList()) {
					std::cout << tag << (j + 1 < item.GetActiveTagList().size() ? ", " : "]");
				}
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "There are no elements in the list" << std::endl;
	}
}
