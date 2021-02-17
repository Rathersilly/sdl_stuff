# Script to extract .tar.gz files - with excess code for enlightenment
# https://stackoverflow.com/questions/856891/unzip-zip-tar-tag-gz-files-with-ruby
require 'rubygems/package'
require 'zlib'
require 'pathname'
#(5..15).each do |x|
#
#filename = "shooter05.tar.gz"
filename = "hi.tar.gz"
File.open(filename, "rb") do  |file|
  Zlib::GzipReader.wrap(file) do |gz|
    Gem::Package::TarReader.new(gz) do |tar|
      tar.each { |entry| puts entry.full_name }
    end
  end
end
path = Pathname(Dir.pwd).join(filename.sub(/\..*/, ''))
Dir.mkdir(path) rescue nil

#future_dir = path.basename
#puts "future dir"
#p path.basename.sub_ext('')
#Dir.mkdir(future_dir) rescue nil

tar_extract = Gem::Package::TarReader.new(Zlib::GzipReader.open(filename))
#tar_extract.rewind # The extract has to be rewinded after every iteration
Dir.chdir(path)


tar_extract.each do |entry|
  #puts entry.full_name
  #puts entry.directory?
  #puts entry.file?
  File.open(entry.full_name, "wb") { |f| f.write(entry.read) }
  puts "extracting #{entry.full_name}"
  # puts entry.read
end
tar_extract.close

#Gem::Package.new("").extract_tar_gz(File.open(filename), path) 

# The following gives error - \\x00\\x00\\x00\\x80?\\xBC\\x01\\x19" is not an octal string (ArgumentError)
#fname = Pathname(Dir.pwd).join(filename)
#target = Gem::Package.new(File.new(fname, "rb"))
#target.extract_files(future_dir)
