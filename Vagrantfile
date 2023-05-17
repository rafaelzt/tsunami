VM_CPUS="2"
VM_MEM="2048"


Vagrant.configure("2") do |config|
  # config.vm.box = "gusztavvargadr/windows-10"
  config.vm.box = "dvgamerr/win-xp-sp3"
  # config.vm.box_version = "0.1.1"
  # Disable USB 2.0 Support
  config.vm.provider "virtualbox" do |vb|
   vb.customize ["modifyvm", :id, "--usb", "on"]
   vb.customize ["modifyvm", :id, "--usbehci", "off"]
  end

  config.vm.define "born2beroot" do |vb|
    vb.vm.hostname = "win-xp-sp3"
    vb.vm.provider "virtualbox" do |v|

      v.name = ENV["VM_NAME"] || "win-xp" # Using ENV_VAR
      v.memory = VM_MEM
      v.cpus = VM_CPUS

    end
  end

end
