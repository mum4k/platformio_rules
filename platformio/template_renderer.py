import jinja2
import json
import sys

# Read parameters
num_parameters = len(sys.argv)
assert num_parameters == 4
template_filename = sys.argv[1]
output_filename = sys.argv[2]
substitutions = json.loads(sys.argv[3])

# Read template file
template_file = open(template_filename, "r")
template_str = template_file.read()
template_file.close()

# Render template
template = jinja2.Environment().from_string(template_str)
rendered_str = template.render(substitutions)

# Write output to desired file
output_file = open(output_filename, "w")
output_file.write(rendered_str)
output_file.close()
