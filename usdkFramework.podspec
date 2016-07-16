Pod::Spec.new do |s|
s.name                = "usdkFramework"
s.version             = "2.3.09"
s.summary             = 'usdk'
s.license             = 'Copyright © 2012-2015 haier.com'
s.author              = { "zhengzx" => "zhengzx@haierubic.com" }
s.homepage            = 'http://www.mob.com'
s.source              = { :git => "https://github.com/wowbby/usdkFramework.git", :tag => s.version.to_s }
s.platform            = :ios, '6.0'
s.libraries           = "sqlite3.0", "c++"
s.vendored_frameworks = 'usdkFramework.framework'
s.resource     = 'configFiles.bundle'
end
