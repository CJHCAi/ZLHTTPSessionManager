Pod::Spec.new do |s|

  s.name         = "ZLHTTPSessionManager"
  s.version      = "0.0.1"
  s.summary      = "基于AFNetworking的马甲库"
  s.description  = "对AFNetworking的请求进行了一层封装，集成了打印日志、检测网络状态、筛除NULL、转换基本数据类型为字符串、将ERROR进行分类等。"

  s.homepage     = "https://github.com/ZLPublicLibrary/ZLHTTPSessionManager"
  s.license      = "MIT"
  s.author             = { "Mr.Zhao" => "itzhaolei@foxmail.com" }
  s.ios.deployment_target = "8.0"
  s.source       = { :git => "https://github.com/ZLPublicLibrary/ZLHTTPSessionManager.git", :tag => s.version }

  s.source_files  = "HTTPSessionManager/Library/*.{h,m}"
  s.exclude_files = ""

  s.framework  = "UIKit","Foundation"
  s.dependency = "AFNetworking", "~> 3.2.1"

end
