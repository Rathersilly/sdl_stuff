# Script to extract .tar.gz files - with excess code for enlightenment
# https://stackoverflow.com/questions/856891/unzip-zip-tar-tag-gz-files-with-ruby
require 'rubygems/package'
require 'zlib'
require 'pathname'
#(5..15).each do |x|
#
base_dir = Dir.pwd
(5..6).each do |n|

  filename = "shooter0#{n}.tar.gz"
  Dir.chdir(base_dir)
  puts "Moving into directory #{base_dir}"
  target_dir = Pathname(Dir.pwd).join(filename.sub(/\..*/, ''))
  begin
    Dir.mkdir(target_dir)
    puts "Creating directory #{target_dir}"
  rescue
    puts "Directory #{target_dir} exists. Continue? (y/n)"
    input = gets.chomp
    exit unless input.start_with?("y")
  end

  tar_extract = Gem::Package::TarReader.new(Zlib::GzipReader.open(filename))
  #tar_extract.rewind # The extract has to be rewinded after every iteration
  Dir.chdir(target_dir)
  puts "Moving into directory #{target_dir}"



  tar_extract.each do |entry|
    File.open(entry.full_name, "wb") { |f| f.write(entry.read) } if entry.file?
    Dir.mkdir(entry.full_name) if entry.directory?
    puts "extracting #{entry.full_name}"
  end
  tar_extract.close
end


#thin
