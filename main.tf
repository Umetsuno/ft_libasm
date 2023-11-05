provider "aws" {
    region = "eu-west-3"
    profile = "Fabien"
}

resource "aws_instance" "example" {
    ami           = "ami-0a4b7ff081ca1ded9"
    instance_type = "t3.small"
    key_name      = "test-ec2-k8s"
    vpc_security_group_ids = ["sg-0a8bc33f276089acf"]

    tags = {
     Name = "kube-master"
    }
}
output "instance_ip_address" {
    value = aws_instance.example.public_ip
}
