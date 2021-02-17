# Script to extracct .tar.gz file the easy way

(5..6).each do |n|
  num = n.to_s
  num = "0#{num}" if num.length == 1
  filename = "shooter#{num}.tar.gz"
  system("tar -xvf #{filename}")
end
