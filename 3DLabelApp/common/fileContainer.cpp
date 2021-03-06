#include "fileContainer.h"

namespace fs = std::experimental::filesystem;

void FileContainer::Init(const std::vector<std::string>& dirsOrFiles)
{
	filepaths.clear();

	for (const auto& path : dirsOrFiles) {
		if (fs::is_directory(path)) {
			// is a dir
			for (const auto& entry : fs::directory_iterator(path)) {
				// check the file format
				if (entry.path().extension().generic_string() == meshFormat) {
					std::string fn = entry.path().generic_string();
					fn = fn.substr(0, fn.find_last_of('.')) + labelFormat;

					fs::path labelFile(fn);
					if (!fs::exists(labelFile))
						filepaths.push_back(entry.path().generic_string());
				}
				else if (fs::is_directory(entry)) {
					for (const auto& e : fs::directory_iterator(entry)) {
						if (e.path().extension().generic_string() == meshFormat) {
							std::string fn = e.path().generic_string();
							fn = fn.substr(0, fn.find_last_of('.')) + labelFormat;
							fs::path labelFile(fn);
							if (!fs::exists(labelFile))
								filepaths.push_back(e.path().generic_string());
						}
					}
				}
			}
		}
		else {
			auto format = path.substr(path.find_last_of('.'));
			if (format == meshFormat || format == ".obj")
				filepaths.push_back(path);
		}
	}
}

std::string FileContainer::Pop()
{
	if (filepaths.empty())
		return std::string();

	std::string file = filepaths[0];
	filepaths.erase(filepaths.begin());

	return file;
}
